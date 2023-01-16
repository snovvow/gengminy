#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, K;
string W;
int arr[1000001];
int cnt[30];
vector<vector<int>> cnt_arr;

int main() {
	for (int i = 'a'; i <= 'z'; i++) {
		vector<int> vt;
		cnt_arr.push_back(vt);
	}

	cin >> T;

	while (T--) {
		cin >> W >> K;

		int ans3 = 1500000;
		int ans4 = -1;
		int len = W.size();
		int left;

		for (int i = 'a'; i <= 'z'; i++) {
			cnt[i - 'a'] = 0;
			cnt_arr[i - 'a'].clear();
		}

		for (int i = 0; i < len; i++) {
			//어떤 알파벳의 인덱스를 기록
			cnt_arr[W[i] - 'a'].push_back(i);
		}
		for (int i = 'a'; i <= 'z'; i++) {
			int arr_len = cnt_arr[i - 'a'].size();

			//길이 K로 유지하여 슬라이딩
			left = 0;
			for (int right = K - 1; right < arr_len; right++) {
				// if (cnt_arr[i - 'a'][right] - cnt_arr[i - 'a'][left] + 1 > ans4)
				ans3 = min(ans3, cnt_arr[i - 'a'][right] - cnt_arr[i - 'a'][left] + 1);
				ans4 = max(ans4, cnt_arr[i - 'a'][right] - cnt_arr[i - 'a'][left] + 1);

				left++;
			}
		}

		if (ans3 == 1500000 || ans4 == -1)
			cout << -1 << endl;
		else
			cout << ans3 << " " << ans4 << endl;
	}
}
