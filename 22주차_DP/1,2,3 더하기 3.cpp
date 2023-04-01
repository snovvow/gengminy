 #include <iostream>
 
 using namespace std;

long long int dp[1000001];

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int T, n;

    cin >> T;
    while (T--) {
        cin >> n;

        for (int i = 2; i <= n; i++) {
            if (dp[i] != 0)
                continue;
            for (int j = 1; i - j > 0 && j <= 3; j++) {
                dp[i] += dp[i - j];
                dp[i] %= 1000000009;
            }
        }

        cout << dp[n] << endl;
    }
}
