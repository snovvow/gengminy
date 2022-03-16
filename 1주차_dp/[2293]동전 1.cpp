/* gengminy _ 22.03.15 */

#include <iostream>
using namespace std;

/* dp[N] : N원을 만드는 경우의 수 */

int dp[10001];

int get_max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main(void)
{
	int n, k, result = 0;
	cin >> n >> k;

	int* coin = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> coin[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (coin[i] <= j)
				dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k] << endl;
}