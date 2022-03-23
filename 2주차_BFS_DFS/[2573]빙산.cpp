#include <iostream>
#include <queue>
using namespace std;

queue<vector<int>> q;
int N, M;
int ice[301][301];
bool hasIce[301][301];
int cpos[] = { 0, 0, 1, -1 };
int rpos[] = { 1, -1, 0, 0 };

void iceDFS(int col, int row)
{
	int nCol, nRow;
	hasIce[col][row] = false;
	for (int i = 0; i < 4; ++i)
	{
		nCol = col + cpos[i];
		nRow = row + rpos[i];
		if (0 <= nCol && nCol < N && 0 <= nRow && nRow < M && hasIce[nCol][nRow])
		{
			iceDFS(nCol, nRow);
		}
	}
}

int countIce(void)
{
	int count;

	/* 빙산 카운트 */
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			hasIce[i][j] = false;
	/* 빙산만 다른 배열에 표시 */
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (ice[i][j] > 0)
				hasIce[i][j] = true;

	count = 0;
	/* 빙산개수 카운트 */
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (hasIce[i][j])
			{
				iceDFS(i, j);
				count++;
			}
		}
	}
	return count;
}

int main(void)
{
	int year = 0;
	int water;
	int nCol, nRow;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> ice[i][j];

	while (countIce() == 1)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (ice[i][j] > 0)
				{
					water = 0;
					for (int k = 0; k < 4; ++k)
					{
						nCol = i + cpos[k];
						nRow = j + rpos[k];
						if (0 <= nCol && nCol < N && 0 <= nRow && nRow < M && ice[nCol][nRow] == 0)
						{
							water++;
						}
					}
					q.push({ i, j, water });
				}
			}
		}

		while (!q.empty())
		{
			nCol = q.front()[0];
			nRow = q.front()[1];
			water = q.front()[2];
			q.pop();
			ice[nCol][nRow] -= water;
			if (ice[nCol][nRow] < 0)
				ice[nCol][nRow] = 0;
		}
		year++;
	}
	if (countIce() > 1)
		cout << year << endl;
	else
		cout << 0 << endl;
}