#include "not.h"

Not::Not(const Formula &op)
  : UnaryConnective (op)
{
  
}

std::ostream &Not::print(std::ostream &out) const
{
  out << "~";
  return operand()->print(out);
}

Formula Not::substitute(const Formula &what, const Formula &with) const
{
  if (equalTo(what))
  {
    return with;
  }
  
  return std::make_shared<Not>(operand()->substitute(what, with));
}

bool Not::eval(const Valuation &val) const
{
  return !operand()->eval(val);
}
