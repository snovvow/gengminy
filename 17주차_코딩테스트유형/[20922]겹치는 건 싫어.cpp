#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num[200001];
int num_count[100001];
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    int left = 0;
    int max_cnt = 0;
    for (int right = 0; right < N; right++) {
        //현재 검사하는 수 개수 증가
        int cur = num[right];
        num_count[cur]++;

        //중복 숫자 수가 K를 넘어서면 해소될때 까지 왼쪽 삭제
        while (num_count[cur] > K && left <= right) {
            num_count[num[left]]--;
            left++;
        }

        if (max_cnt < right - left + 1)
            max_cnt = right - left + 1;
    }
    cout << max_cnt << endl;
}
