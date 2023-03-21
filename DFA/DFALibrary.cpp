#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Define the DFA state machine
class DFA {
private:
    vector<int> final_states; 
    map<pair<int, char>, int> transition_function; 
    int current_state; 

public:
    DFA(vector<int> final_states, map<pair<int, char>, int> transition_function, int initial_state) {
        this->final_states = final_states;
        this->transition_function = transition_function;
        this->current_state = initial_state;
    }

    bool process(string input_string) {
        for (char c : input_string) {
            if (transition_function.count({ current_state, c })) {
                current_state = transition_function[{current_state, c}];
            }
            else {
                return false; 
            }
        }
        if (find(final_states.begin(), final_states.end(), current_state) != final_states.end()) {
            return true; 
        }
        else {
            return false; 
        }
    }

    void reset() {
        current_state = 0;
    }

    int get_current_state() {
        return current_state;
    }

    void set_current_state(int state) {
        current_state = state;
    }
};

