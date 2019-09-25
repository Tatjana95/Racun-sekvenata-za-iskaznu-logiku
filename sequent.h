#ifndef SEQUENT_H
#define SEQUENT_H

#include <vector>
#include "base_formula.h"

class Sequent;
using Seq = std::shared_ptr<Sequent>;
using SequentVec =std::vector<Formula>;
class Proof;

class Sequent : public std::enable_shared_from_this<Sequent>
{
public:
    Sequent(SequentVec&& l = SequentVec(),
            SequentVec&& r = SequentVec());

    std::shared_ptr<Proof> getProof();

    void print(std::ostream & ostr) const;

protected:
    SequentVec _left;
    SequentVec _right;
};

std::ostream & operator << (std::ostream & ostr, const Sequent & seq);
std::ostream & operator << (std::ostream & ostr, const Seq & seq);

#endif // SEQUENT_H
