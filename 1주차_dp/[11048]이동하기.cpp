/* gengminy _ 22.03.15 */

#include <iostream>
using namespace std;

int main(void)
{
	int N, M;
	int** map;
	int** dp;

	/* input */
	cin >> N >> M;
	map = new int* [N];
	dp = new int* [N];
	for (int i = 0; i < N; ++i)
	{
		map[i] = new int[M];
		dp[i] = new int[M];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			dp[i][j] = 0;
		}
	}
	/* end input */

	/* dp */

	int x[] = { -1, -1, 0 };
	int y[] = { 0, -1, -1 };
	int max;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			max = 0;
			for (int k = 0; k < 3; ++k)
			{
				int prevCol = i + y[k];
				int prevRow = j + x[k];
				if (0 <= prevCol && prevCol < N && 0 <= prevRow && prevRow < M)
					if (dp[prevCol][prevRow] > max)
						max = dp[prevCol][prevRow];
			}
			dp[i][j] = max + map[i][j];
		}
	}
	cout << dp[N - 1][M - 1] << endl;
}
