//[BOJ] 주식 / 실버2
//https://www.acmicpc.net/problem/11501

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int T, N;
    long long profit;
    //일자별 주식 가격
    int arr[1000001];

    scanf("%d", &T);
    while (T--) {
        //이익
        int max_val = 0;
        profit = 0;

        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        max_val = arr[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            if (max_val < arr[i])
                max_val = arr[i];
            else {
                profit += max_val - arr[i];
            }
        }

        printf("%lld\n", profit);
    }
}