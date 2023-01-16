#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int ans_left = -1;
	int ans_right = -1;
	int ans = 2100000000;
	int left = 0;
	int right = N - 1;
	while (left < right) {
		int sol_left = arr[left];
		int sol_right = arr[right];
		int sol_mix = sol_left + sol_right;

		if (abs(sol_mix) < ans) {
			ans = abs(sol_mix);
			ans_left = sol_left;
			ans_right = sol_right;
		}

		if (sol_mix < 0)
			left++;
		else
			right--;
	}

	cout << ans_left << " " << ans_right << endl;
}
