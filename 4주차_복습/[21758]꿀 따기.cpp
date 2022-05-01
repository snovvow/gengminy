#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
int dp[100001];

int get_max(int a, int b)
{
	return a > b ? a : b;
}
int main(void) {
	ios::sync_with_stdio(0);
	int max = 0;
	int sum = 0;
	int N, tmp;

	//입력과 동시에 누적합 기록
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &tmp);
		if (i == 0)
			dp[i] = tmp;
		else
			dp[i] = dp[i - 1] + tmp;
	}

	// total : dp[N - 1]
	// bee bee pot
	for (int i = 1; i < N - 1; ++i) {
		//bee_left : dp[N - 1] - dp[0] - (dp[i] - dp[i - 1]) =>고정
		//bee_right : dp[N - 1] - dp[i]
		max = get_max(max, dp[N - 1] - dp[0] - (dp[i] - dp[i - 1]) + dp[N - 1] - dp[i]);
	}

	// pot bee bee
	for (int i = 1; i < N - 1; ++i) {
		//bee_left : dp[i - 1]
		//bee_right : dp[N - 2] - (dp[i] - dp[i - 1])
		max = get_max(max, dp[i - 1] + dp[N - 2] - (dp[i] - dp[i - 1]));
	}

	// bee pot bee
	for (int i = 1; i < N - 1; ++i) {
		//bee_left : dp[i] - dp[0]
		//bee_right : dp[N - 1] - dp[i - 1] - (dp[N - 1] - dp[N - 2]);
		max = get_max(max, dp[i] - dp[0] + dp[N - 1] - dp[i - 1] - (dp[N - 1] - dp[N - 2]));
	}

	printf("%d", max);
}