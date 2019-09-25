#include "constant.h"


True::True()
  : AtomicFormula ()
{
  
}

std::ostream &True::print(std::ostream &out) const
{
  return out << "TRUE";
}

bool True::eval(const Valuation &val) const
{
  UNUSED_VARIABLE(val);
  return true;
}

False::False()
  : AtomicFormula ()
{
  
}

std::ostream &False::print(std::ostream &out) const
{
  return out << "FALSE";
}

bool False::eval(const Valuation &val) const
{
  UNUSED_VARIABLE(val);
  return false;
}
