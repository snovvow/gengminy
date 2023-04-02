#include <iostream>
#include <queue>
using namespace std;

int N;
int map[501][501];
int dp[501][501];

int ans;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	if (dp[y][x]) return dp[y][x];
	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (map[y][x] < map[ny][nx]) {
				dp[y][x] = max(dp[y][x], 1 + dfs(nx, ny));
			}
		}
	}
	ans = max(dp[y][x], ans);
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	queue<pair<int, int>> cur;
	cur.push(make_pair(0, 0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dfs(i, j);
		}
	}

	cout << ans << endl;
	
}
