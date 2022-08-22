/**
 * [17244]아맞다우산.cpp
 * 골드2
 * 2022-08-22
 * https://www.acmicpc.net/problem/17244
 */

#include <iostream>
#include <string>
#include <queue>
using namespace std;
string map[50];
bool visit[50][50][36];
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pair<int, int> S; //start
	pair<int, int> E; //exit
	int itemCount = 0;

	queue<vector<int>> q;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'S')
				S = make_pair(i, j);
			else if (map[i][j] == 'X') {
				map[i][j] = itemCount + '0';
				itemCount++;
			}
		}
	}

	int cpos[] = { 0, 0, 1, -1 };
	int rpos[] = { 1, -1, 0, 0 };
	/* col, row, time, count */
	q.push({ S.first, S.second, 0, 0 });

	while (!q.empty()) {
		int row = q.front()[0];
		int col = q.front()[1];
		int time = q.front()[2];
		int check = q.front()[3];

		q.pop();

		/* 모든 아이템을 찾고 문에 도착하면 */
		if (map[row][col] == 'E' && check == (1 << itemCount) - 1) {
			cout << time << endl;
			return 0;
		}

		int ncol, nrow;

		for (int i = 0; i < 4; i++) {
			nrow = row + rpos[i];
			ncol = col + cpos[i];

			if (nrow < 0 || nrow >= M
				|| ncol < 0 || ncol >= N || map[nrow][ncol] == '#')
				continue;
				
			/* 찾아야 하는 다음 아이템 */
			int ncheck = check | (1 << (map[nrow][ncol] - '0'));

			if ('0' <= map[nrow][ncol] && map[nrow][ncol] < '5'
				&& !visit[nrow][ncol][ncheck]) {
				visit[nrow][ncol][ncheck] = true;
				q.push({ nrow, ncol, time + 1, ncheck });
				continue;
			}

			if (!visit[nrow][ncol][check]) {
				visit[nrow][ncol][check] = true;
				q.push({ nrow, ncol, time + 1, check });
			}
		}

	}

	return 0;
}
