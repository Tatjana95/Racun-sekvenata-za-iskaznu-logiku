#include "proof.h"
#include "sequent.h"

Proof::Proof(Seq s, std::string ru, Confirmation l, Confirmation r)
    : _seq(s), _rule(ru), _left(l), _right(r)
{
}

void Proof::print(std::ostream & ostr, unsigned depth) const
{
    for (unsigned i=0; i<depth; ++i)
        ostr << "\t";
    ostr << _seq<<" ";
    printRule(ostr);
    ostr<<"\n";
    if (_left)
        _left->print(ostr,depth+1);
    if (_right)
        _right->print(ostr,depth+1);
}

void Proof::printRule(std::ostream & ostr) const
{
    if(_rule == "AND_L")
        ostr << "/\\L";
    if(_rule == "AND_R")
        ostr << "/\\R";
    if(_rule == "OR_L")
        ostr << "\\/L";
    if(_rule == "OR_R")
        ostr << "\\/R";
    if(_rule == "NOT_L")
        ostr << "~L";
    if(_rule == "NOT_R")
        ostr << "~R";
    if(_rule == "IMP_L")
        ostr << "=>L";
    if(_rule == "IMP_R")
        ostr << "=>R";
    if(_rule == "FALSE_L")
        ostr << "~L";
    if(_rule == "TRUE_R")
        ostr << "TR";
    if(_rule == "ASS")
        ostr << "ass";
}

std::ostream & operator << (std::ostream & ostr, const Proof & proof)
{
  proof.print(ostr,0);
  return ostr;
}

std::ostream & operator << (std::ostream & ostr, const Confirmation & proof)
{
  proof->print(ostr,0);
  return ostr;
}
