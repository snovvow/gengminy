
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
string tmp = "";

void find(string s, string t) {

    if (s == t) {
        cout << 1 << endl;
        exit(0);
    }
    if (s.length() >= t.length())
        return;

    if (t[t.size() - 1] == 'A') {
        tmp = t;
        tmp.erase(tmp.size() - 1);
        find(s, tmp);
    }
    if (t[0] == 'B') {
        tmp = t;
        tmp.erase(tmp.begin());
        reverse(tmp.begin(), tmp.end());
        find(s, tmp);
    }
}

int main() {

    cin >> S >> T;
    find(S, T);
    cout << 0 << endl;
}