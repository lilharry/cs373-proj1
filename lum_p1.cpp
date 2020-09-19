#include "State.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


int main(int argc, char * argv[]){
    if (argc != 4){
        cout << "args should be filename language transitions" << endl;
        exit(1);
    }
    string file = argv[1];
    char * language = &(argv[2])[0];
    
    int num_transitions = stoi(argv[3]);
    
    string line;
    ifstream myfile (file);
    
    if (myfile.is_open())
    {
        
        while ( getline (myfile,line) )
        {
            istringstream ss(line);
            string input_type;
            ss >> input_type;

            if (input_type == "state"){
                int num;
                string type = "";
                ss >> num;
                if (ss){
                    ss >> type;
                }
                
                State s(num, type);
                
                State::states[num] = s;
                
            }
            else if (input_type == "transition"){
                int q;
                char a;
                int r;
                char b;
                char x;
                ss >> q;
                ss >> a;
                ss >> r;
                ss >> b;
                ss >> x;
                State::states[q].addTransition(q, a, r, b, x);
                
            }

        }
        myfile.close();
    }

    else {
        cout << "Unable to open file";
        exit(1);
    }
   
    /*
    for (auto s : State::states){
        cout << s.second.num << " " << s.second.is_accept << endl;
        for (auto e : s.second.t){
            cout << "yay" << endl;
        } 
    }
    */

    int i = 0;
    State curr_state;
    for (auto s : State::states){
        
        if (s.second.is_start){
            curr_state = s.second;
            break;
        }
    }
    if (curr_state.num == -1){
        cout << "error" << endl;
        exit(1);
    }
    //cout << curr_state.num << endl;
    bool first_transition = true;
    for (int cnt = 0; cnt < num_transitions; cnt++){
        
        for (auto t : curr_state.t){
            if (t.a == language[i]){
                if (!first_transition){
                   cout << "->"; 
                }else{
                    cout << t.q << "->";
                }
                first_transition = false;

                language[i] = t.b;
                if (t.x == 'R'){
                    i++;
                }
                if (t.x == 'L'){
                    i--;
                }
                curr_state = State::states[t.r];
                cout << t.r;
                break;
            }      
        }
    }
    cout << " ";
    if (curr_state.is_accept){
        cout << "accept";
    }else if (curr_state.is_reject){
        cout << "reject";
    }else{
        cout << "quit";
    }
    cout << endl;
    return 0;
}
