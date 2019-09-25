#ifndef OR_H
#define OR_H

#include "binary_connective.h"

class Or : public BinaryConnective
{
public:
  Or(const Formula &op1, const Formula &op2);
  
  virtual std::string symbol() const;
  
  virtual Formula substitute(const Formula &what, const Formula &with) const;
  
  virtual bool eval(const Valuation &val) const;
};

#endif // OR_H
