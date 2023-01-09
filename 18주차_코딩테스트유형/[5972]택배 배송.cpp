#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

int N, M;

vector<pair<int, int>> vtx[50001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;

		vtx[a].push_back(make_pair(b, c));
		vtx[b].push_back(make_pair(a, c));
	}

	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>> pq;

	dist[1] = 0;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int d = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0; i < vtx[node].size(); i++) {
			int next_dist = d + vtx[node][i].second;
			int next_node = vtx[node][i].first;

			if (next_dist < dist[next_node]) {
				dist[next_node] = next_dist;
				pq.push({ -next_dist, next_node });
			}
		}
	}

	cout << dist[N] << endl;
}
