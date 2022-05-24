#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

int map[125][125];
int dist[125][125];
int nc[] = { 0, 0, 1, -1 };
int nr[] = { 1, -1, 0, 0 };

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a[2] > b[2];
	}
};

int dijkstra(int N) {
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j)
			dist[i][j] = INF;

	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	pq.push({ 0, 0, map[0][0]}); //v[0,0] -> v[0,0]의 비용 0
	dist[0][0] = map[0][0];

	while (!pq.empty()) {
		int cCol = pq.top()[0];
		int cRow = pq.top()[1];
		int w = pq.top()[2];
		pq.pop();

		for (int i = 0; i < 4; ++i) {
			int nCol = cCol + nc[i];
			int nRow = cRow + nr[i];

			if (0 <= nCol && nCol < N && 0 <= nRow && nRow < N) {
				int nDist = map[nCol][nRow] + w;

				if (dist[nCol][nRow] > nDist) {
					dist[nCol][nRow] = nDist;
					pq.push({ nCol, nRow, nDist });
				}
			}
		}
	}
	return dist[N-1][N-1];
}

int main(void) {
	int N, T;
	T = 0;
	while (++T) {
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				cin >> map[i][j];
		}
		cout << "Problem " << T << ": " << dijkstra(N) << endl;
	}
}