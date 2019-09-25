#include "atomic_formula.h"

AtomicFormula::AtomicFormula()
  : BaseFormula ()
{
  
}

unsigned AtomicFormula::complexity() const
{
  return 0;
}

Formula AtomicFormula::substitute(const Formula &what, const Formula &with) const
{
  if (equalTo(what))
  {
    return with;
  }
  
  return std::const_pointer_cast<BaseFormula>(shared_from_this());
}
