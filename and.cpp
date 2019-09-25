#include "and.h"

And::And(const Formula &op1, const Formula &op2)
  :BinaryConnective (op1, op2)
{
  
}

std::string And::symbol() const
{
  return "/\\";
}

Formula And::substitute(const Formula &what, const Formula &with) const
{
  return substituteImpl<And>(what, with);
}

bool And::eval(const Valuation &val) const
{
  Formula op1, op2;
  std::tie(op1, op2) = operands();
  
  return op1->eval(val) && op2->eval(val);
}
