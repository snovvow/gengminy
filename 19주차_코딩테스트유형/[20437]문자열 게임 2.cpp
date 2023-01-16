#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, K;
string W;
int arr[1000001];
int cnt[30];
vector<vector<int>> cnt_arr;

//배열 카운트 초기화
void init() {
	for (int i = 'a'; i <= 'z'; i++) {
		cnt[i - 'a'] = 0;
		cnt_arr[i - 'a'].clear();
	}
}

// n개 등장하는 문자가 있는지 체크
bool check(int n) {
	for (int i = 'a'; i <= 'z'; i++) {
		if (cnt[i - 'a'] == n)
			return true;
	}
	return false;
}

// n개 등장하는 문자가 이 알파벳인지 체크
bool check(int n, char ch) {
	for (int i = 'a'; i <= 'z'; i++) {
		if (cnt[i - 'a'] == n && ch == (char)i)
			return true;
	}
	return false;
}

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

		//3번
		init();
		int left = 0;
		for (int right = 0; right < len; right++) {

			//현재 알파벳 카운트
			cnt[W[right] - 'a']++;

			//가장 짧은 연속 길이 재기
			while (left <= right && check(K)) {
				if (right - left + 1 < ans3)
					ans3 = right - left + 1;
				//알파벳 카운트 감소
				cnt[W[left] - 'a']--;
				left++;
			}
		}

		//4번
		init();
		for (int i = 0; i < len; i++) {
			//어떤 알파벳의 인덱스를 기록
			cnt_arr[W[i] - 'a'].push_back(i);
		}
		for (int i = 'a'; i <= 'z'; i++) {
			int arr_len = cnt_arr[i - 'a'].size();

			//길이 K로 유지하여 슬라이딩
			left = 0;
			for (int right = K - 1; right < arr_len; right++) {
				if (cnt_arr[i - 'a'][right] - cnt_arr[i - 'a'][left] + 1 > ans4)
					ans4 = cnt_arr[i - 'a'][right] - cnt_arr[i - 'a'][left] + 1;

				left++;
			}
		}

		//for (int i = 'a'; i <= 'z'; i++) {
		//	int arr_len = cnt_arr[i - 'a'].size();
		//	cout << (char)i << " :";

		//	if (arr_len == 0)
		//		cout << 0 << " ";
		//	for (int left = 0; left < arr_len; left++)
		//		cout << cnt_arr[i - 'a'][left] << " ";
		//	cout << endl;
		//} ///


		if (ans3 == 1500000 || ans4 == -1)
			cout << -1 << endl;
		else
			cout << ans3 << " " << ans4 << endl;
	}
}
