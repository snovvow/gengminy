#include <iostream>
#include <string>
#include <queue>
using namespace std;

string input[1000];
bool isVisit[1000][1000][2]; //[col][row][벽 부셨는지 여부]
queue<vector<int>> q;

int main(void)
{
	int cpos[] = {0, 0, 1, -1};
	int rpos[] = {1, -1, 0, 0};
	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> input[i];

	// col, row, canBreakWall, move
	q.push({0, 0, 1, 1});
	isVisit[0][0][0] = true;
	while (!q.empty())
	{
		int col, row, canBreakWall, move;
		int nCol, nRow;

		col = q.front()[0];
		row = q.front()[1];
		canBreakWall = q.front()[2];
		move = q.front()[3];
		q.pop();

		if (col == N - 1 && row == M - 1)
		{
			cout << move << endl;
			return 0;
		}

		for (int i = 0; i < 4; ++i)
		{
			nCol = col + cpos[i];
			nRow = row + rpos[i];
			if (0 <= nCol && nCol < N && 0 <= nRow && nRow < M)
			{
				if (!isVisit[nCol][nRow][canBreakWall])
				{
					if (input[nCol][nRow] == '0')
					{
						q.push({ nCol, nRow, canBreakWall, move + 1 });
						isVisit[nCol][nRow][canBreakWall] = true;
					}
					else if (canBreakWall && input[nCol][nRow] == '1')
					{
						q.push({ nCol, nRow, 0, move + 1 });
						isVisit[nCol][nRow][0] = true;
					}
				}
			}
		}
	}
	cout << -1 << endl;
}


/*
3차원 배열을 써야하는 이유
반례

7 6 
000000
111110
010000
010111
010011
011011
000010

000000
111110
010000
010111
010011
011011
000*10
* 지점에서 오류 발생

*/
