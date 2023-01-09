#include <iostream>
#include <vector>
using namespace std;

int N, M, L, K;
int x, y;

vector<pair<int, int>> vt;

int main(void){
    int x1, x2, y1, y2;
    int ans = 0;
    int cnt = 0;

    cin >> N >> M >> L >> K;

    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        vt.push_back(make_pair(x, y));
    }
    
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            cnt = 0;
            x1 = vt[i].first;
            y1 = vt[j].second;

            for (int k = 0; k < K; k++) {
                x2 = vt[k].first;
                y2 = vt[k].second;
                if (x1 <= x2 && x2 <= x1 + L && y1 <= y2 && y2 <= y1 + L)
                    cnt++;
            }

            ans = cnt > ans ? cnt : ans;
        }
    }
    cout << K - ans << endl;
}
