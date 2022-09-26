#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int sushi[300001];
bool check[3001];

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second > b.second)
        return true;
    else if (a.second == b.second) {
        if (a.first.length() > b.first.length())
            return true;
        else if (a.first.length() == b.first.length() && a.first.compare(b.first) < 0) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, int> words;
    map<string, int>::iterator it;
    
    int N, M;
    cin >> N >> M;

    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input.length() >= M) {
            //이미 존재하는 단어면
            it = words.find(input);
            if (it != words.end()) {
                int cnt = it->second;

                
 /*               cout << input << " => " + cnt << endl;*/

                words.erase(it);
                words.insert({ input, cnt + 1 });
            }
            else {
                words.insert({ input, 1 });
            }
        }
    }

    vector<pair<string, int>> v(words.begin(), words.end());
    sort(v.begin(), v.end(), cmp);

    for (pair<string, int> it : v) {
        cout << it.first << "\n";
    }

    return 0;
}
