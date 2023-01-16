#include <iostream>

using namespace std;

int N, S;
int arr[1000001];
int main() {
	int current_sum = 0;
	int len_min = 1500000;
	int left = 0;
	int right = 0;

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	for (right = 0; right < N; right++) {
		current_sum += arr[right];

		//합이 S 이상이 되면 그 중 가장 짧은 길이 선택
		while (current_sum >= S && left <= right) {
			int current_length = right - left + 1;

			if (current_length < len_min)
				len_min = current_length;

			current_sum -= arr[left];
			left++;
		}
	}

	if (len_min == 1500000)
		cout << 0 << endl;
	else
		cout << len_min << endl;
}
