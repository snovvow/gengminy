#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void backtracking(int idx) {
    
}

bool isValid(string str) {
    
}

int main(void) {
    string input;

    while (1){
        cin >> input;
        
        if (input == "end") {
            return 0;
        }

        if (isValid(input))
            cout << "valid" << "\n";
        else
            cout << "invalid" << "\n";    
        
    }
}