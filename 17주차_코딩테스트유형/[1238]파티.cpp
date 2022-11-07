#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2000000000
using namespace std;

int distx[1001];
vector<pair<int, int>> graph[2][1001];
vector<int> dist[2];

int N, M, X;
// 최소 거리 행렬을 반환함
void dijkstra(int k)
{
    dist[k][X] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, X });
    while (!pq.empty()) {
        int d = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d > dist[k][now]) continue;

        for (int i = 0; i < graph[k][now].size(); i++) {
            int next = graph[k][now][i].second;
            int next_d = d + graph[k][now][i].first;

            if (next_d < dist[k][next]) {
                dist[k][next] = next_d;
                pq.push({ next_d,next });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int a, b, c;

    fill_n(distx, 1001, INF);
    cin >> N >> M >> X;


    //정방향으로 검사 후 역방향으로 추가 검사
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[0][a].push_back({ c, b });
        graph[1][b].push_back({ c, a });
    }

    dist[0].resize(N + 1, INF);
    dist[1].resize(N + 1, INF);

    dijkstra(0);
    dijkstra(1);

    int ret = 0;

    for (int i = 1; i <= N; i++) {
        ret = max(ret, dist[0][i] + dist[1][i]);
    }

    cout << ret << '\n';

    return 0;
}
