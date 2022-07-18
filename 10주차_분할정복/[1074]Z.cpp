/*  
*   [BOJ]Z / 실버1
*   https://www.acmicpc.net/problem/1074
*/

#include <iostream>
using namespace std;

int cnt, N, R, C;
bool isFind = false;
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
		for (int i = 0; i < 4; ++i) {
			int nRow = rn[i] + row;
			int nCol = cn[i] + col;

			if (nRow == R && nCol == C)
			{
				isFind = true;
				return;
			}
			cnt++;
		}
		return;
	}
	
	int sqr = (int)pow(2, size - 1);
	for (int i = 0; i < 4; ++i) {
		int nRow = sqr * rn[i] + row;
		int nCol = sqr * cn[i] + col;

		if (nRow <= R && R < nRow + sqr) {
			if (nCol <= C && C < nCol + sqr) {
				cnt += sqr * sqr * i;
				solve(nRow, nCol, size - 1);
				return;
			}
		}
	}
}

int main(void) {
	cin >> N >> R >> C;

	solve(0, 0, N);

	cout << cnt << endl;
}
