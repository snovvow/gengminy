#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        return a.second > b.second;
    }
    return false;
}

int height[366]; // 가로 방문 및 높이 동시 체크

vector<pair<int, int>> vt;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, x, y;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        vt.push_back(make_pair(x, y));
    }

    sort(vt.begin(), vt.end(), cmp);

    for (int i = 0; i < N; i++) {
        int left = vt[i].first;
        int right = vt[i].second;

        for (int i = left; i <= right; i++) {
            height[i]++;
        }
    }

    int max_height = 0;
    int len = 0;
    int sum = 0; //정답
    for (int i = 0; i < 366; i++) {
        if (height[i] == 0) {
            sum += max_height * len;
            max_height = 0;
            len = 0;
        }
        else {
            max_height = max(max_height, height[i]);
            len++;
        }
    }
    sum += max_height * len;
    cout << sum << endl;
}
