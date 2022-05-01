#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool isVisit[50][50];
int cpos[] = { 0, 0, 1, -1 };
int rpos[] = { 1, -1, 0, 0 };
int main(void)
{
	int R, C;
	string map[51];
	cin >> R >> C;
	for (int i = 0; i < R; ++i)
		cin >> map[i];

	queue<vector<int>> q;
	pair<int, int> dest;
	pair<int, int> st;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (map[i][j] == 'S')
			{
				st = make_pair(i, j);
				isVisit[i][j] = true;
			}
			else if (map[i][j] == 'D')
				dest = make_pair(i, j);
			else if (map[i][j] == '*')
			{
				q.push({ 1, i, j, 0 });
				isVisit[i][j] = true;
			}
			else if (map[i][j] == 'X')
				isVisit[i][j] = true;
		}
	}

	q.push({ 0, st.first, st.second, 0 });

	while (!q.empty())
	{
		int elem = q.front()[0];
		int col = q.front()[1];
		int row = q.front()[2];
		int move = q.front()[3];
		q.pop();

		if (elem == 0 && map[col][row] == 'D')
		{
			cout << move;
			return 0;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nCol = col + cpos[i];
			int nRow = row + rpos[i];

			if (0 <= nCol && nCol < R && 0 <= nRow && nRow < C && !isVisit[nCol][nRow])
			{
				if (elem == 1 && map[nCol][nRow] == 'D')
					continue;
				q.push({ elem, nCol, nRow, move + 1 });
				isVisit[nCol][nRow] = true;				
			}
		}
	}
	cout << "KAKTUS";
}
