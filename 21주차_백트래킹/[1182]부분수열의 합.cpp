//실버 2

#include <iostream>

using namespace std;

int N, S;
int arr[21];
// count 반환
int backtracking(int idx, int sum) {
    int count_in_scope = 0;
    // 합이 같으면
    if (sum == S) {
        count_in_scope++;
    }
    for (int i = idx + 1; i < N; i++) {
        sum += arr[i];
        count_in_scope += backtracking(i, sum);
        sum -= arr[i];
    }
    return count_in_scope;
}

int main() {
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        count += backtracking(i, arr[i]);
    }
    cout << count << endl;
}