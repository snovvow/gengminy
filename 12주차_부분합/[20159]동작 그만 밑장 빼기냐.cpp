#include <iostream>
#include <cstdio>
using namespace std;

int N;
int card[100001];
int sum[100001][2];
int res[100001];

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &card[i]);
    }

    for (int i = 0; i < N; ++i) {
        //홀수번째(정훈)
        if ((i + 1) % 2 == 0) {
            sum[i / 2 + 1][0] = sum[i / 2][0] + card[i];
        }
        else {
            sum[i / 2 + 1][1] = sum[i / 2][1] + card[i];
        }
    }
    int max = 0;

    for (int i = 1; i <= N; i++) {
        int idx = i / 2 + 1;
        if (i % 2 == 0) {
            res[i] = sum[idx - 1][1] + (sum[N / 2 - 1][0] - sum[idx - 2][0]);
        }
        else {
            res[i] = sum[idx - 1][1] + (sum[N / 2 - 1][0] - sum[idx - 1][0]) + card[N - 1];
        }
        if (max < res[i])
            max = res[i];
    }

    printf("%d\n", max);

    return 0;
}
