#include <iostream>
using namespace std;

int w, h;
int map[301][301];
int cpos[] = { 0, 0, 1, -1 , 1, 1, -1, -1};
int rpos[] = { 1, -1, 0, 0, 1, -1, 1, -1};

void DFS(int col, int row)
{
	int nCol, nRow;
	map[col][row] = 0;
	for (int i = 0; i < 8; ++i)
	{
		nCol = col + cpos[i];
		nRow = row + rpos[i];
		if (0 <= nCol && nCol < h && 0 <= nRow && nRow < w && map[nCol][nRow])
		{
			DFS(nCol, nRow);
		}
	}
}

int countIsland(void)
{
	int count;

	count = 0;
	/* 섬 개수 카운트 */
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (map[i][j])
			{
				DFS(i, j);
				count++;
			}
		}
	}
	return count;
}

int main(void)
{
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				cin >> map[i][j];

		cout << countIsland() << endl;
	}
}