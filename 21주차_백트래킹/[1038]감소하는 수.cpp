//골드 5

#include <iostream>
#include <vector>
using namespace std;

int N;
int count_in_scope = -1;
vector<int> current_num;

// 제일 시작 num, 자릿수
bool backtracking(int fnum, int len) {
    if (current_num.size() == len) {
        count_in_scope++;

        if (count_in_scope == N) {
            return true;
        }
    } else {
        for (int i = 0; i < fnum; i++) {
            current_num.push_back(i);
            if (backtracking(i, len))
                return true;
            current_num.pop_back();
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    int len = 1; //자릿수
    while (1) {
        int check = count_in_scope;
        current_num.clear();
        for (int i = 0; i < 10; i++) {
            current_num.push_back(i);
            if (backtracking(i, len)) {
                for (int l = 0; l < current_num.size(); l++)
                    cout << current_num[l];
                return 0;
            }
            current_num.pop_back();
        }
        if (count_in_scope == check) {
            cout << -1;
            return 0;
        }
        len++;
    }
}
