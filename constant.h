#ifndef CONSTANT_H
#define CONSTANT_H

#include "atomic_formula.h"

class True : public AtomicFormula
{
public:
  True();
  
  virtual std::ostream& print(std::ostream &out) const;
  
  virtual bool eval(const Valuation &val) const;
};

class False : public AtomicFormula
{
public:
  False();
  
  virtual std::ostream& print(std::ostream &out) const;
  
  virtual bool eval(const Valuation &val) const;
};

#endif // CONSTANT_H
