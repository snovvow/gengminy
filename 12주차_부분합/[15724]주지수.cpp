#include <iostream>
#include <cstdio>
using namespace std;

int N, M, K;
int map[1025][1025];
int sum[1025][1025];

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &map[i][j]);
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + map[i][j];
		}
	}
	//부분합 미리 계산

	cin >> K;
	int x1, y1, x2, y2;

	for (int i = 0; i < K; ++i) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int count = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
		printf("%d\n", count);
	}

	return 0;
}

//cout cin 때문에 시간초과