#ifndef TRUE_H
#define TRUE_H

#include "logicconstant.h"

class True : public LogicConstant {

public:
  virtual void printFormula(std::ostream & ostr) const;
  virtual Type getType() const;
};

#endif // TRUE_H
