/*  
*   [BOJ]색종이 만들기 / 실버2
*   https://www.acmicpc.net/problem/2630
*/

#include <iostream>
using namespace std;

bool map[128][128];
int N;
int blue, white;
int rn[] = { 0, 0, 1, 1 };
int cn[] = { 0, 1, 0, 1 };

int pow(int num, int c) {
	int ret = 1;
	for (int i = 0; i < c; ++i)
		ret *= num;
	return ret;
}

void solve(int row, int col, int size) {
	if (size == 1) {
		if (map[row][col])
			blue++;
		else
			white++;
		return;
	}

	bool cur = map[row][col];

	int i, j;
	for (i = row; i < row + size; ++i) {
		for (j = col; j < col + size; ++j) {
			if (cur != map[i][j]) {
				//한개라도 일치하지 않으면 그냥 재귀 돌려버림
				for (int z = 0; z < 4; ++z) {
					int nRow = size / 2 * rn[z] + row;
					int nCol = size / 2 * cn[z] + col;

					solve(nRow, nCol, size / 2);
				}
				return;
			}
		}
	}

	//전체가 일치
	if (cur)
		blue++;
	else
		white++;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	solve(0, 0, N);
	cout << white << endl << blue << endl;
}
