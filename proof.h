#ifndef PROOF_H
#define PROOF_H

#include "sequent.h"
#include <string>

class Proof;
typedef std::shared_ptr<Proof> Confirmation;

class Proof
{
public:

    Proof(Seq s, std::string ru, Confirmation l = nullptr, Confirmation r = nullptr);
    void print(std::ostream & ostr, unsigned depth) const;
    void printRule(std::ostream & ostr) const;

protected:
    Seq _seq;
    std::string _rule;
    Confirmation _left;
    Confirmation _right;
};

std::ostream & operator << (std::ostream & ostr, const Proof & proof);
std::ostream & operator << (std::ostream & ostr, const Confirmation & poof);

#endif
