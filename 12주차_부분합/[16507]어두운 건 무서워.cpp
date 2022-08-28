#include <iostream>
#include <cstdio>
using namespace std;

int R, C, Q;
int map[1001][1001];
int sum[1001][1001];

int main() {
	scanf("%d %d %d", &R, &C, &Q);

	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			scanf("%d", &map[i][j]);
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + map[i][j];
		}
	}
	//부분합 미리 계산

	int x1, y1, x2, y2;

	for (int i = 0; i < Q; ++i) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int count = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
		int rem = count / ((x2 - x1 + 1) * (y2 - y1 + 1));
		printf("%d\n", rem);
	}

	return 0;
}