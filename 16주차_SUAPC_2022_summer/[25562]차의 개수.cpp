//[BOJ] 차의 개수 / 실버4
//https://www.acmicpc.net/problem/25562

#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int N;
    cin >> N;

    cout << N * (N - 1) / 2 << "\n";

    int num = 1;

    for (int i = 0; i < N - 1; ++i) {
        cout << num << " ";
        num *= 2;
    }
    cout << num << "\n";
    cout << N - 1 << "\n";

    for (int i = 1; i < N; ++i) {
        cout << i << " ";
    }
    cout << N << "\n";
}
