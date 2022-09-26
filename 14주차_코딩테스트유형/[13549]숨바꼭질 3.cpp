#include <iostream>
#include <queue>

using namespace std;

bool visit[100001];
int main(void){

    int N, K;
    cin >> N >> K;

    queue<pair<int, int> > q;

    q.push(make_pair(N, 0));
    visit[N] = true;

    while (!q.empty()) {
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (pos == K) {
            cout << cnt << endl;
            return 0;
        }

        if (pos > 0 && pos * 2 <= 100000 && !visit[pos * 2]) {
            q.push(make_pair(pos * 2, cnt));
            visit[pos * 2] = true;
        }
        if (pos > 0 && !visit[pos - 1]) {
            q.push(make_pair(pos - 1, cnt + 1));
            visit[pos - 1] = true;
        }
        if (pos < 100000 && !visit[pos + 1]) {
            q.push(make_pair(pos + 1, cnt + 1));
            visit[pos + 1] = true;
        }
    }

    return 0;
}