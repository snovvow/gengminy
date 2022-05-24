#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

int N, D;
vector<pair<int, int>> edge[10001];
vector<int> dist(10001);

int main(void) {
	cin >> N >> D;

	// 1칸마다 간선 초기화
	for (int i = 0; i <= D; ++i) {
		edge[i].push_back(make_pair(i + 1, 1)); //다음칸 까지 가는 비용 1
		dist[i] = INF; //연결되지 않음으로 초기화
	}

	int B, E, W;
	for (int i = 0; i < N; ++i) {
		cin >> B >> E >> W;
		edge[B].push_back(make_pair(E, W)); //B에서 E로 가는데 W만큼 비용 발생
	}

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 0)); //출발 정점 (0 -> 0)
	dist[0] = 0;
	
	while (!pq.empty()) {
		int cur = pq.top().first;
		int w = -pq.top().second; //길이가 짧은 것이 먼저 오도록 하기 위한 음수화
		pq.pop();

		for (int i = 0; i < edge[cur].size(); ++i) {
			int next = edge[cur][i].first;
			int nextW = edge[cur][i].second + w;

			if (dist[next] > nextW) {
				dist[next] = nextW;
				pq.push({ next, -nextW });
			}
		}
	}

	cout << dist[D];
}