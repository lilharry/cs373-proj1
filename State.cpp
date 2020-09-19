#include "State.h"
#include <iostream>
using namespace std;

map<int, State> State::states;

State::State(){
    num = -1;
    is_accept = false;
    is_reject = false;
    is_start = false;
     
}
State::State(int num){
    this->num = num;
    is_accept = false;
    is_reject = false;
    is_start = false;
 }

State::State(int num, string type){
    this->num = num;
    is_accept = false;
    is_reject = false;
    is_start = false;
    if (type == "accept"){
        this->is_accept = true;
    }
    else if (type == "reject"){
        this->is_reject = true;
    }
    else if (type == "start"){
        this->is_start = true;
    }
    
};

State::~State(){

}

void State::addTransition(int q, char a, int r, char b, char x){
    if (states[q].num == -1){
        states[q].num = q;
    }
    if (states[r].num == -1){
        states[r].num == r;
    }
    State::Transition new_t(q, a, r, b, x);
    states[q].t.push_back(new_t);


}
