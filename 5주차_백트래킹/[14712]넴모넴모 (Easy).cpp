#include <iostream>
using namespace std;

int N, M;
bool map[26][26];
int cnt;

//현재 칸을 뒀을때 넴모가 만들어지지 않으면 true
bool isNemmo(int col, int row)
{
	if (map[col - 1][row] && map[col][row - 1] && map[col - 1][row - 1])
		return true;
	return false;
}

void backtracking(int index) {
	if (index == N * M)
		cnt++;
	else {
		int col = index / M + 1;
		int row = index % M + 1;

		backtracking(index + 1);
		if (!isNemmo(col, row)) {
			map[col][row] = true;
			backtracking(index + 1);
			map[col][row] = false;
		}
        //현재칸을 채운 것과 안채운 경우를 나누어 트래킹
	}
}

int main(void) {
	cin >> N >> M;
	backtracking(0);
	cout << cnt << endl;
}
