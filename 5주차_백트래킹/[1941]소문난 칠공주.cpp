#include <iostream>
#include <string>
#include <queue>
using namespace std;

string map[5];
bool isVisit[5][5];
bool checkVisit[5][5];
int cnt;
int cpos[] = { 0, 0, 1, -1 };
int rpos[] = { 1, -1, 0, 0 };


void check7dfs(int col, int row)
{
	int nCol, nRow;

	checkVisit[col][row] = false;
	for (int k = 0; k < 4; ++k) {
		nCol = col + cpos[k];
		nRow = row + rpos[k];
		if (0 <= nCol && nCol < 5 && 0 <= nRow && nRow < 5 && checkVisit[nCol][nRow]) {
			check7dfs(nCol, nRow);
		}
	}
}

// dfs 횟수가 딱 1번이어야 모두가 연결된 것
bool check7(void) {
	int callcnt = 0;

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			checkVisit[i][j] = isVisit[i][j];

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if (checkVisit[i][j])
			{
				callcnt++;
				check7dfs(i, j);
			}

	if (callcnt == 1)
		return true;
	return false;
}

// col: i / 5, row : i % 5
void backtracking(int index, int depth, int dasom) {
	if (depth == 7)
	{
		if (dasom >= 4 && check7())
			cnt++;
		return;
	}
	for (int i = index; i < 25; ++i)
	{
		isVisit[i / 5][i % 5] = true;
		if (map[i / 5][i % 5] == 'S')
			backtracking(i + 1, depth + 1, dasom + 1);
		else
			backtracking(i + 1, depth + 1, dasom);
		isVisit[i / 5][i % 5] = false;
	}
}

int main(void) {
	for (int i = 0; i < 5; ++i)
		cin >> map[i];

	backtracking(0, 0, 0);
	cout << cnt << endl;
}