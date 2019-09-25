#include "base_formula.h"

#include <typeinfo>

BaseFormula::BaseFormula()
{
  
}

void BaseFormula::getAtoms(AtomSet &aset) const
{
  UNUSED_VARIABLE(aset);
}

bool BaseFormula::equalTo(const Formula &f) const
{
  const BaseFormula *base = f.get();
  return typeid (*this) == typeid (*base);
}

BaseFormula::~BaseFormula()
{
  
}

OptionalValuation BaseFormula::isSatisfiable() const
{
  AtomSet aset;
  getAtoms(aset);
  Valuation val{aset};
  do {
    if (eval(val))
    {
      return val;
    }
  } while (val.next());
  
  return {};
}

OptionalValuation BaseFormula::isNotTautology() const
{
  AtomSet aset;
  getAtoms(aset);
  Valuation val{aset};
  do {
    if (!eval(val))
    {
      return val;
    }
  } while (val.next());
  return {};
}

bool BaseFormula::isEquivalent(const Formula &f) const
{
  AtomSet aset;
  getAtoms(aset);
  f->getAtoms(aset);
  Valuation val{aset};
  do {
    if (eval(val) != f->eval(val))
    {
      return false;
    }
  } while (val.next());
  return true;
}

void BaseFormula::printTruthTable(std::ostream &out) const
{
  AtomSet aset;
  getAtoms(aset);
  Valuation v{aset};
  out << std::noboolalpha;
  do {
    out << v << " | " << eval(v) << '\n'; 
  } while (v.next());
}

bool BaseFormula::isConsequence(const Formula &f) const
{
  AtomSet aset;
  getAtoms(aset);
  f->getAtoms(aset);
  Valuation val{aset};
  do {
    if (eval(val) && !f->eval(val))
    {
      return false;
    }
  } while (val.next());
  return true;
}

bool operator==(const Formula &lhs, const Formula &rhs)
{
  return lhs->equalTo(rhs);
}

bool operator!=(const Formula &lhs, const Formula &rhs)
{
  return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &out, const Formula &f)
{
  return f->print(out);
}
