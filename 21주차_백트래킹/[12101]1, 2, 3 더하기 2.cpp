//실버 1

#include <iostream>
#include <vector>
using namespace std;

int n, k;
int count_in_scope;
vector<int> ret;

// count 반환
bool backtracking(int num, int sum) {
    if (sum == n) {
        count_in_scope++;
        if (count_in_scope == k) {
            ret.push_back(num);
            return true;
        }
    }
    for (int i = 1; i <= 3; i++) {
        if (sum + i <= n) {
            backtracking(i, sum + i);

            if (count_in_scope == k) {
                ret.push_back(num);
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= 3; i++) {
        bool result = backtracking(i, i);

        if (result) {
            
            for (int i = ret.size() - 1; i >= 0; i--) {
                cout << ret[i];
                if (i != 0)
                    cout << "+";
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}