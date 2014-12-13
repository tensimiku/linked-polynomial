//
//  main.cpp
//  ds_linkedpoly
//
//  Created by KakaKim on 2014. 12. 8..
//  Copyright (c) 2014년 kakakim. All rights reserved.
//

#include <iostream>

class Term{
public:
    int coef;
    int exp;
    Term* link;
    Term(int c, int e) : coef(c), exp(e) ,link(NULL) {}
};

class Polynomial{
private:
    Term *first, *last;
public:
    Polynomial() : first(NULL),last(NULL){}
    void addTerm(int coef,int exp);
    Polynomial* addPoly(Polynomial *b);
    void printPoly();
};
void Polynomial::addTerm(int coef, int exp){
    Term *temp = new Term(coef, exp);
    if(first){
        last->link = temp;
        last = last -> link;
    } else{
        first = last = temp;
    }
}
Polynomial* Polynomial::addPoly(Polynomial *b){
    Term* af = first;
    Term* bf = b->first;
    Polynomial *c = new Polynomial();
    while(af&&bf){
        if(af->exp==bf->exp){
            int sum = af->coef + bf->coef;
            if(sum) c->addTerm(sum, af->exp );
            af = af->link; bf = bf->link;
        }
        else if(af->exp<bf->exp){
            c->addTerm(bf->coef, bf->exp);
            bf = bf->link;
        }
        else{
            c->addTerm(af->coef, af->exp);
            af = af->link;
        }
    }
    while(af){
        c->addTerm(af->coef, af->exp);
        af = af->link;
    }
    while(bf){
        c->addTerm(bf->coef, bf->exp);
        bf = bf->link;
    }
    return c;
}

void Polynomial::printPoly(){
    Term* start = first;
    while(start){
        std::cout<<start->coef;
        if(start->exp!=0)
            std::cout<<"x^"<<start->exp;
        start = start->link;
        if(start != NULL && start->coef>0){
            std::cout<<"+";
        }
    }
    
    std::cout<<std::endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Polynomial* a = new Polynomial();
    Polynomial* b = new Polynomial();
    a->addTerm(2, 7);
    a->addTerm(2, 3);
    a->addTerm(5, 2);
    a->addTerm(-3, 1);
    a->addTerm(10, 0);
    b->addTerm(5, 5);
    b->addTerm(-2, 3);
    b->addTerm(-3, 2);
    b->addTerm(7, 1);
    b->addTerm(-8, 0);
    
    Polynomial* c= a->addPoly(b);
    a->printPoly();
    b->printPoly();
    c->printPoly();
    return 0;
}
