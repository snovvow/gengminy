#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

vector<pair<int, int>> edge[5001]; //간선 그래프

int V, E, P;

int dijkstra(int start, int end) {
	vector<int> dist(V + 1, INF); //거리 1부터 V까지 INF로 초기화
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 }); //v[start]의 비용 0
	dist[start] = 0;

	while (!pq.empty()) {
		int cur = pq.top().first;
		int w = -pq.top().second;
		pq.pop();

		for (int i = 0; i < edge[cur].size(); ++i) {
			int next = edge[cur][i].first;
			int nextDist = edge[cur][i].second + w;

			if (dist[next] > nextDist) {
				dist[next] = nextDist;
				pq.push({ next, -nextDist });
			}
		}
	}
	return dist[end];
}

int main(void) {
	int A, B, C;
	cin >> V >> E >> P;

	for (int i = 0; i < E; ++i) {
		cin >> A >> B >> C;
		edge[A].push_back({ B, C });
		edge[B].push_back({ A, C });
		// A -> B 의 비용은 C
	}

	// 민준->건우, 건우->마산 == 민준->마산 이면 경로 위에 건우가 있는 것임
	if (dijkstra(1, P) + dijkstra(P, V) == dijkstra(1, V))
		cout << "SAVE HIM" << endl;
	else
		cout << "GOOD BYE" << endl;
}