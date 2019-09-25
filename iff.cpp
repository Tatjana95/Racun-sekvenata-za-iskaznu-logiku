#include "iff.h"

Iff::Iff(const Formula &op1, const Formula &op2)
  :BinaryConnective (op1, op2)
{
  
}

std::string Iff::symbol() const
{
  return "<=>";
}

Formula Iff::substitute(const Formula &what, const Formula &with) const
{
  return substituteImpl<Iff>(what, with);
}

bool Iff::eval(const Valuation &val) const
{
  Formula op1, op2;
  std::tie(op1, op2) = operands();
  
  return op1->eval(val) == op2->eval(val);
}
