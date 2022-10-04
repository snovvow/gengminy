//[BOJ] 진우의 달 여행 (Small) / 실버3
//https://www.acmicpc.net/problem/17484

#include <iostream>
#include <vector>
# define INF 1000000
using namespace std;

int arr[9][9];
//x, y, 전에 있던 칸(0좌 1중간 2우)
int dp[9][9][3];
int main() {
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            for (int k = 0; k < 3; k++){
                 dp[i][j][k] = INF;
            }
        }
    }

    for (int j = 0; j < M; j++){
        dp[0][j][0] = arr[0][j];
        dp[0][j][1] = arr[0][j];
        dp[0][j][2] = arr[0][j];
    }

    //다음칸 부터 검사 시작
    for (int i = 1; i < N; i++) {
        for (int k = 0; k < M; k++) {

            //좌측에서 접근 가능하면
            if (k == 0) {
                dp[i][k][0] = min(dp[i - 1][k + 1][1], dp[i - 1][k + 1][2]) + arr[i][k];
                dp[i][k][1] = dp[i - 1][k][0] + arr[i][k];
            }
            //우측에서 접근
            else if (k == M - 1) {
                dp[i][k][1] = dp[i - 1][k][2] + arr[i][k];
                dp[i][k][2] = min(dp[i - 1][k - 1][0], dp[i - 1][k - 1][1]) + arr[i][k];
            }
            //중간에서 접근
            else {
                dp[i][k][0] = min(dp[i - 1][k + 1][1], dp[i - 1][k + 1][2]) + arr[i][k];
                dp[i][k][1] = min(dp[i - 1][k][0], dp[i - 1][k][2]) + arr[i][k];
                dp[i][k][2] = min(dp[i - 1][k - 1][0], dp[i - 1][k - 1][1]) + arr[i][k];
            }
        }
    }

    int result = INF;
    for (int i = 0; i < M; i++) {
        for (int k = 0; k < 3; k++){
          result = min(result, dp[N - 1][i][k]);
        }
    }

    cout << result;
}