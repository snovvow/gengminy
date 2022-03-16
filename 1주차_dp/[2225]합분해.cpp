/* gengminy _ 22.03.16 */

#include <iostream>
using namespace std;

int dp[201][201];

int main(void)
{
	int N, K;

	cin >> N >> K;
	if (K == 1)
		cout << 1 << endl;
	else
	{
		for (int i = 0; i <= N; ++i)
			dp[1][i] = 1;

		for (int i = 1; i <= K; ++i)
			for (int j = 0; j <= N; ++j)
				for (int k = 0; k <= j; ++k)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000000;

		cout << dp[K][N] << endl;
	}
}