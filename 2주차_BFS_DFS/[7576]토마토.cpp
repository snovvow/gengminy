/* gengminy _ 22.03.16 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int map[1001][1001];
bool visit[1001][1001];

int main(void)
{
	int M, N;
	int result = 0;
	queue<vector<int>> q;

	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				q.push({ i, j, 0 });
				visit[i][j] = 1;
			}
			else if (map[i][j] == -1)
				visit[i][j] = 1;
		}
	}

	int col, row, count = -1, nCol, nRow;
	int x[] = { 0, 0, 1, -1 };
	int y[] = { 1, -1, 0, 0 };
	while (!q.empty())
	{;
		col = q.front()[0];
		row = q.front()[1];
		count = q.front()[2];
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			nCol = col + y[i];
			nRow = row + x[i];
			if (0 <= nCol && nCol < N && 0 <= nRow && nRow < M && !visit[nCol][nRow])
			{
				visit[nCol][nRow] = 1;
				q.push({ nCol, nRow, count + 1 });
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!visit[i][j])
			{
				printf("-1\n");
				return (0);
			}
		}
	}
	printf("%d\n", count);
	return (0);
}