#ifndef IFF_H
#define IFF_H

#include "binary_connective.h"

class Iff : public BinaryConnective
{
public:
  Iff(const Formula &op1, const Formula &op2);
  
  virtual std::string symbol() const;
  
  virtual Formula substitute(const Formula &what, const Formula &with) const;
  
  virtual bool eval(const Valuation &val) const;
};

#endif // IFF_H
