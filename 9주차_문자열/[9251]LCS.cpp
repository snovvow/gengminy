#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[1001][1001];
int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    string A, B;

    cin >> A >> B;

    int lenA = A.length();
    int lenB = B.length();

    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[lenA][lenB];

    return 0;
}
