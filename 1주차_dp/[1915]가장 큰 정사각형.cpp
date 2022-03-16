/* gengminy _ 22.03.15 */

#include <iostream>
#include <string>
using namespace std;

int get_min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
int main(void)
{
	int n, m;
	string* map;
	int** dp;
	int result = 0;

	cin >> n >> m;
	map = new string[n];
	dp = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> map[i];
		dp[i] = new int[m];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i == 0 || j == 0)
				dp[i][j] = (map[i][j] - '0');
			else if (map[i][j] == '1')
				dp[i][j] = get_min(dp[i - 1][j], get_min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
			else
				dp[i][j] = 0;
			if (dp[i][j] > result)
				result = dp[i][j];
		}
	}
	cout << result * result << endl;
}
