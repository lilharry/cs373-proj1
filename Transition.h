#ifndef TRANSITION_H
#define TRANSITION_H
#include "State.h"

using namespace std;

class State;

class Transition{
    public:
        State * q;
        char a;
        State * r;
        char b;
        char x;
        Transition(State * q, char a, State * r, char b, char x){
            this->q = q;
            this->a = a;
            this->r = r;
            this->b = b;
            this->x = x;
        }
        ~Transition(){
            delete q;
            delete r;
        };
};

#endif
