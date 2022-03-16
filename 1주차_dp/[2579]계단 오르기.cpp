/* gengminy _ 22.03.16 */

#include <iostream>
using namespace std;

int arr[301];
int dp[301][2];

int get_max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main(void)
{
	int N;

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	/* dp[N][0] - 이전칸에서 2칸 뛰어 오름
	dp[N][1] - 이전칸에 연속된 1칸을 오름 */

	dp[1][0] = arr[1];
	dp[2][0] = arr[2];
	dp[2][1] = arr[1] + arr[2];
	for (int i = 3; i <= N; ++i)
	{
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + arr[i];
		dp[i][1] = dp[i - 1][0] + arr[i];
	}
	cout << get_max(dp[N][0], dp[N][1]) << endl;
}