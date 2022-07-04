#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
    string input;

    cin >> input;
    vector<char> st;

    int len = input.length();
    int idx;
    for (int i = 0; i < len; ++i){
        st.push_back(input[i]);
        idx = st.size() - 1; //현재 인덱스 - 3 -2 -1 0 검사
        if (idx > 3 && st[idx - 3] == 'P' && st[idx - 2] == 'P'
            && st[idx - 1] == 'A' && st[idx] == 'P'){
                st.pop_back();
                st.pop_back();
                st.pop_back();
        }
    }
    if (st.size() == 1 && st[0] == 'P')
        cout << "PPAP";
    else
        cout << "NP";

    return 0;
}
