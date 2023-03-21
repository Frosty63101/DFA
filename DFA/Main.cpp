#include <iostream>
#include <string>
#include <sstream>
#include "DFALibrary.cpp"

int main() {
    map<pair<int, char>, int> transition_function = {
        
    };

    cout << "Current transition function map:" << endl;
    for (auto const& entry : transition_function) {
        cout << "(" << entry.first.first << ", " << entry.first.second << ") -> " << entry.second << endl;
    }

    while (true) {
        cout << "Enter a state, input symbol, and next state to add or modify (enter 'q' to quit):" << endl;
        int current_state, next_state;
        char input_symbol;
        string input;
        cin >> input;

        if (input == "q") {
            break;
        }
        else {
            current_state = stoi(input);
            cin >> input_symbol;
            cin >> next_state;
            transition_function[{current_state, input_symbol}] = next_state;
        }
    }

    cout << "Updated transition function map:" << endl;
    for (auto const& entry : transition_function) {
        cout << "(" << entry.first.first << ", " << entry.first.second << ") -> " << entry.second << endl;
    }

    cout << "enter sample" << endl;
    string sample;
    cin >> sample;

    vector<int> final_states = { 0 };

    DFA dfa(final_states, transition_function, 0);

    cout << dfa.process(sample) << endl; 

    dfa.reset();
    dfa.set_current_state(2);

    cout << dfa.process("1010") << endl; 
    cout << dfa.process("001") << endl; 
}