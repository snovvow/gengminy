#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001][3];
int main() {
    int N, a, b;
    int cnt = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        arr[a][0] = b;
    }

    int max_height = 0;
    for (int i = 0; i <= 1000; i++) {
        max_height = max(max_height, arr[i][0]);
        arr[i][1] = max_height;
    }

    max_height = 0;
    for (int i = 1000; i >= 0; i--){
        max_height = max(max_height, arr[i][0]);
        arr[i][2] = max_height;
    }

    for (int i = 0; i <= 1000; i++) {
        cnt += min(arr[i][1], arr[i][2]);
    }
    cout << cnt << endl;
}
