#include "sequent.h"

#include <iostream>
#include <string>

#include "propositional_logic.h"

#include "proof.h"

Sequent::Sequent(SequentVec&& l, SequentVec&& r)
    :   _left(l),
        _right(r)
{
}

void Sequent::print(std::ostream & ostr) const
{
    if (!_left.empty())
    {
        auto i = _left.begin();
        ostr << *i++;
        for (auto e = _left.end(); i!=e; ++i)
            ostr << ", " << *i ;
    }
    ostr << " |- ";
    if (!_right.empty())
    {
        auto j = _right.begin();
        ostr << *j++;
        for (auto e = _right.end(); j!=e; ++j)
            ostr << ", " << *j ;
    }
}

std::shared_ptr<Proof> Sequent::getProof()
{

    for (auto i = _left.begin(), el = _left.end(); i!=el; ++i)
    {
        //Logicka konstanta (F)L
        if(BaseFormula::isOfType<False>(*i))
        {
            if (_right.empty())
                return std::make_shared<Proof>(std::make_shared<Sequent>(SequentVec{*i}), "FALSE_L");
            return std::make_shared<Proof>(shared_from_this(), "", std::make_shared<Proof>(std::make_shared<Sequent>(SequentVec{*i}), "FALSE_L"));
        }

        //Negacija ~L
        if(BaseFormula::isOfType<Not>(*i))
        {
            SequentVec left_cpy = _left;
            SequentVec right_cpy = _right;
            auto j = left_cpy.begin();
            left_cpy.erase(j);

            Formula op = ((UnaryConnective*)(*i).get())->operand();
            right_cpy.push_back(op);

            Seq child = std::make_shared<Sequent>(std::move(left_cpy), std::move(right_cpy));
            Confirmation proof = child->getProof();
            if (proof)
                return std::make_shared<Proof>(shared_from_this(), "NOT_L", proof);
        }
        // konjunkcija //\L
        if(BaseFormula::isOfType<And>(*i))
        {
            SequentVec left_cpy = _left;
            SequentVec right_cpy = _right;
            auto j = left_cpy.begin();
            left_cpy.erase(j);

            Formula op1, op2;
            std::tie(op1, op2) = ((BinaryConnective*)(*i).get())->operands();
            left_cpy.push_back(op1);
            left_cpy.push_back(op2);

            Seq child = std::make_shared<Sequent>(std::move(left_cpy), std::move(right_cpy));
            Confirmation proof = child->getProof();
            if (proof)
                return std::make_shared<Proof>(shared_from_this(), "AND_L", proof);
        }

        // disjunkcija \\/L
        if(BaseFormula::isOfType<Or>(*i))
        {
            Formula op1, op2;
            std::tie(op1, op2) = ((BinaryConnective*)(*i).get())->operands();
            SequentVec left_cpy1 = _left;
            SequentVec right_cpy1 = _right;
            SequentVec left_cpy2 = _left;
            SequentVec right_cpy2 = _right;
            auto j1 = left_cpy1.begin();
            auto j2 = left_cpy2.begin();
            left_cpy1.erase(j1);
            left_cpy2.erase(j2);

            left_cpy2.push_back(op2);

            left_cpy1.push_back(op1);

            Seq child_left = std::make_shared<Sequent>(std::move(left_cpy1), std::move(right_cpy1));
            Seq child_right = std::make_shared<Sequent>(std::move(left_cpy2), std::move(right_cpy2));
            Confirmation proof_left = child_left->getProof();
            if (proof_left)
            {
                Confirmation proof_right = child_right->getProof();
                if (proof_right)
                    return std::make_shared<Proof>(shared_from_this(), "OR_L", proof_left, proof_right);
            }
        }
       //implikacija =>L
        if(BaseFormula::isOfType<Imp>(*i))
        {
            Formula op1, op2;
            std::tie(op1, op2) = ((BinaryConnective*)(*i).get())->operands();
            SequentVec left_cpy1 = _left;
            SequentVec right_cpy1 = _right;
            SequentVec left_cpy2 = _left;
            SequentVec right_cpy2 = _right;
            auto j1 = left_cpy1.begin();
            auto j2 = left_cpy2.begin();

            left_cpy1.erase(j1);
            left_cpy2.erase(j2);

            left_cpy2.push_back(op2);

            right_cpy1.push_back(op1);

            Seq child_left = std::make_shared<Sequent>(std::move(left_cpy1), std::move(right_cpy1));
            Seq child_right = std::make_shared<Sequent>(std::move(left_cpy2), std::move(right_cpy2));
            Confirmation proof_left = child_left->getProof();
            if (proof_left)
            {
                Confirmation proof_right = child_right->getProof();
                if (proof_right)
                    return std::make_shared<Proof>(shared_from_this(), "IMP_L", proof_left, proof_right);
            }
        }

    }
    //Logicka konstanta TR
    for (auto i = _right.begin(), el = _right.end(); i!=el; ++i)
    {
        if(BaseFormula::isOfType<True>(*i))
        {
            if (_left.empty())
                return std::make_shared<Proof>(std::make_shared<Sequent>(SequentVec{},SequentVec{*i}), "TRUE_R");

            return std::make_shared<Proof>(shared_from_this(),"", std::make_shared<Proof>(std::make_shared<Sequent>(SequentVec{},SequentVec{*i}), "TRUE_R"));
        }

        // negacija ~R
        if(BaseFormula::isOfType<Not>(*i))
        {
            SequentVec left_cpy = _left;
            SequentVec right_cpy = _right;
            auto j = right_cpy.begin();
            right_cpy.erase(j);

            Formula op = ((UnaryConnective*)(*i).get())->operand();
            left_cpy.push_back(op);

            Seq child = std::make_shared<Sequent>(std::move(left_cpy), std::move(right_cpy));
            Confirmation proof = child->getProof();
            if (proof)
                return std::make_shared<Proof>(shared_from_this(), "NOT_R", proof);
        }
        // disjunkcija \\/R
        if(BaseFormula::isOfType<Or>(*i))
        {
            SequentVec left_cpy = _left;
            SequentVec right_cpy = _right;
            auto j = right_cpy.begin();
            right_cpy.erase(j);

            Formula op1, op2;
            std::tie(op1, op2) = ((BinaryConnective*)(*i).get())->operands();
            right_cpy.push_back(op2);
            right_cpy.push_back(op1);

            Seq child = std::make_shared<Sequent>(std::move(left_cpy), std::move(right_cpy));
            Confirmation proof = child->getProof();
            if (proof)
                return std::make_shared<Proof>(shared_from_this(), "OR_R", proof);
        }
        // implikacija =>R
        if(BaseFormula::isOfType<Imp>(*i))
        {
            SequentVec left_cpy = _left;
            SequentVec right_cpy = _right;
            auto j = right_cpy.begin();
            right_cpy.erase(j);

            Formula op1, op2;
            std::tie(op1, op2) = ((BinaryConnective*)(*i).get())->operands();
            right_cpy.push_back(op2);
            left_cpy.push_back(op1);

            Seq child = std::make_shared<Sequent>(std::move(left_cpy), std::move(right_cpy));
            Confirmation proof = child->getProof();
            if (proof)
                return std::make_shared<Proof>(shared_from_this(), "IMP_R", proof);
        }
         //konjunkcija /\\R
        if(BaseFormula::isOfType<And>(*i))
        {
            Formula op1, op2;
            std::tie(op1, op2) = ((BinaryConnective*)(*i).get())->operands();

            SequentVec left_cpy1 = _left;
            SequentVec right_cpy1 = _right;
            SequentVec left_cpy2 = _left;
            SequentVec right_cpy2 = _right;
            auto j1 = right_cpy1.begin();
            auto j2 = right_cpy2.begin();

            right_cpy1.erase(j1);
            right_cpy2.erase(j2);
            right_cpy1.push_back(op1);
            right_cpy2.push_back(op2);

            Seq con_right1 = std::make_shared<Sequent>(std::move(left_cpy1), std::move(right_cpy1));
            Seq con_right2 = std::make_shared<Sequent>(std::move(left_cpy2), std::move(right_cpy2));

            Confirmation proof_left = con_right1->getProof();
            if (proof_left)
            {
                Confirmation proof_right = con_right2->getProof();
                if (proof_right)
                    return std::make_shared<Proof>(shared_from_this(), "AND_R", proof_left, proof_right);
            }
        }
    }


    //assumption
    for (auto i = _left.begin(), el = _left.end(); i!=el; ++i)
        if(BaseFormula::isOfType<AtomicFormula>(*i))
            for (auto j = _right.begin(), er = _right.end(); j!=er; ++j)
                if ((*i)->equalTo(*j))
                    return std::make_shared<Proof>(shared_from_this(), "ASS");

    // nismo nasli resenje
    return nullptr;
}


std::ostream & operator << (std::ostream & ostr, const Sequent & seq)
{
    seq.print(ostr);
    return ostr;
}


std::ostream & operator << (std::ostream & ostr, const Seq & seq)
{
    seq->print(ostr);
    return ostr;
}
