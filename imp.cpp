#include "imp.h"

Imp::Imp(const Formula &op1, const Formula &op2)
  :BinaryConnective (op1, op2)
{
  
}

std::string Imp::symbol() const
{
  return "=>";
}

Formula Imp::substitute(const Formula &what, const Formula &with) const
{
  return substituteImpl<Imp>(what, with);
}

bool Imp::eval(const Valuation &val) const
{
  Formula op1, op2;
  std::tie(op1, op2) = operands();
  
  return !op1->eval(val) || op2->eval(val);
}
