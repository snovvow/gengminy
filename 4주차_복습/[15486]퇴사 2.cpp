#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int, int>> input;
int dp[1500001];

int main(void) {
	int N, T, P;
	int max = 0;
	int maxidx = 0;
	int cur, curidx;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> T >> P;
		input.push_back(make_pair(T, P));
	}

	for (int i = 0; i < N; ++i)
	{
		if (i > 0 && dp[i - 1] > dp[i])
			dp[i] = dp[i - 1];

		curidx = i + input[i].first;
		cur = dp[i] + input[i].second;

		if (curidx <= N) {
			if (dp[curidx] < cur)
				dp[curidx] = cur;
			if (cur > max) {
				max = cur;
				maxidx = curidx;
			}
		}
	}


	cout << max;
}
