#include <iostream>
#include <cstdio>

using namespace std;

int N, M, K;
int map[2000][2000];

int cpos[] = { 1, -1 };
int rpos[] = { 1, -1 };

int main() {
	int count = 0;
	int tmpx, tmpy;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 1) {
				count++;
				tmpx = i; tmpy = j;
			}
		}
	}

	//교차안함
	if (2 * K == count) {
		printf("0");
	}
	//1칸
	else if (K == 1) {
		printf("%d\n", 2 * K - count);
		printf("%d %d", tmpx + 1, tmpy + 1);
	}
	else {
		printf("%d\n", 2 * K - count);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//상하좌우 모두 있으면 교차로 판정
				if (map[i][j] == 1) {
					bool cflag = false;
					bool rflag = false;

					for (int k = 0; k < 2; k++) {
						int ncol = i + cpos[k];
						if (0 <= ncol && ncol < N && map[ncol][j] == 1) {
							cflag = true;
						}
						int nrow = j + rpos[k];
						if (0 <= nrow && nrow < M && map[i][nrow] == 1) {
							rflag = true;
						}
					}

					if (cflag && rflag) {
						printf("%d %d\n", i + 1, j + 1);
						exit(0);
					}
				}
			}
		}

		int scol = 2001, ecol = -1;
		int srow = 2001, erow = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					scol = min(i, scol);
					srow = min(j, srow);
					ecol = max(i, ecol);
					erow = max(j, erow);
				}
			}
		}

		if (srow == erow) {
			for (int i = 0; i < 2 * K - count; i++) {
				printf("%d %d\n", scol + count - K + i + 1, srow + 1);
			}
		}
		else if (scol == ecol) {
			for (int i = 0; i < 2 * K - count; i++) {
				printf("%d %d\n", scol + 1, srow + count - K + i + 1);
			}
		}
	}
}