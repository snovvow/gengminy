// 골드3

#include <iostream>

using namespace std;

int N, M;
int mem[101];
int cost[101];

int dp[101][10001];   // 최소로 해야하는 값 (최대비용 10000)

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int cost_sum = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) 
        cin >> mem[i];
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        cost_sum += cost[i];
    }

    // j 의 비용 소모로 얻을 수 있는 최대 W
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= cost_sum; j++) {
            if (j - cost[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + mem[i]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

	for (int i = 0; i <= cost_sum; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i << endl;
			break;
		}	
	}
    return 0;
}

//