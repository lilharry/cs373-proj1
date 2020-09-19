#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class State{
    
    public:
        static map<int, State> states;
        class Transition{
            public:
                int q;
                char a;
                int r;
                char b;
                char x;
                Transition(int q, char a, int r, char b, char x){
                    this->q = q;
                    this->a = a;
                    this->r = r;
                    this->b = b;
                    this->x = x;
                }
                ~Transition(){};
        };

        int num;
        bool is_reject;
        bool is_accept;
        bool is_start;
        vector<Transition> t;
        State();        
        State(int num);
        State(int num, string type);
        ~State();
        static void addTransition(int q, char a, int r, char b, char x);
};

#endif
