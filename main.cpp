#include "propositional_logic.h"
#include <iostream>

#include <sequent.h>
#include<proof.h>

using namespace std;

int main()
{
    Formula A = std::make_shared<Atom>(0);
    Formula B = std::make_shared<Atom>(1);

    Formula f0 = std::make_shared<Or>(A,B);
    Formula f1 = std::make_shared<Not>(f0);
    Formula f2 = std::make_shared<Not>(A);
    Formula f3 = std::make_shared<Not>(B);
    Formula f4 = std::make_shared<And>(f2,f3);
    Formula f5 = std::make_shared<Imp>(f1,f4);
    Seq s0 = std::make_shared<Sequent>(SequentVec{f1},SequentVec{f4});
    std::cout << s0 << std::endl;

    Confirmation proof0 = (*s0).getProof();
    std::cout << "Proof print:" << std::endl;
    if (proof0== nullptr)
        std::cout << "No proof" << std::endl;
    else
        std::cout << proof0 << std::endl;

    std::cout << std::endl <<std::endl;

    Formula C = std::make_shared<Atom>(2);
    Formula D = std::make_shared<Atom>(3);

    Formula f6 = std::make_shared<And>(C,D);
    Formula f7 = std::make_shared<Imp>(f6,C);
    Seq s1 = std::make_shared<Sequent>(SequentVec{f6}, SequentVec{C});

    std::cout << s1 << std::endl;

    Confirmation proof1 = (*s1).getProof();
    std::cout << "Proof:" << std::endl;
    if (proof1== nullptr)
        std::cout << "No proof" << std::endl;
    else
        std::cout << proof1 << std::endl;

    Formula E = std::make_shared<Atom>(4);
    Formula F = std::make_shared<Atom>(5);

    Formula f8 = std::make_shared<And>(E, F);
    Formula f9 = std::make_shared<Not>(f8);
    Seq s2 = std::make_shared<Sequent>(SequentVec{f8}, SequentVec{f9});

    std::cout << std::endl <<std::endl;

    std::cout << s2 << std::endl;

    Confirmation proof2 = (*s2).getProof();
    std::cout << "Proof:" << std::endl;
    if (proof2== nullptr)
        std::cout << "No proof" << std::endl;
    else
        std::cout << proof2 << std::endl;


    Formula G = std::make_shared<Atom>(4);
    Formula H = std::make_shared<Atom>(5);
    Formula f10 = std::make_shared<And>(G, H);
    Formula f11 = std::make_shared<Not>(H);
    Seq s3 = std::make_shared<Sequent>(SequentVec{f10}, SequentVec{f11});

    std::cout << std::endl <<std::endl;

    std::cout << s3 << std::endl;

    Confirmation proof3 = (*s3).getProof();
    std::cout << "Proof:" << std::endl;
    if (proof3== nullptr)
        std::cout << "No proof" << std::endl;
    else
        std::cout << proof3 << std::endl;



    return 0;
}
