#include <iostream>
using namespace std;

int N, K, B;
bool arr[100001];

int main() {
	int tmp;
	int count = 0;
	int min;
	cin >> N >> K >> B;

	//false: GOOD, true: 고쳐야함
	for (int i = 0; i < B; ++i) {
		cin >> tmp;
		arr[tmp] = true;
	}

	//슬라이딩 윈도우 초기화 및 초기 고쳐야하는 개수 설정
	for (int i = 1; i <= K; ++i) {
		//고쳐야하면
		if (arr[i]) {
			//갯수추가
			count++;
		}
	}

	min = count;

	//한칸씩 이동하면서 검사, 맨왼쪽칸과 맨오른쪽 칸만 검사함
	for (int i = K + 1; i <= N; ++i) {
		int left = i - K; //맨왼쪽 (현재 제외된 칸)
		int right = i; //맨 오른쪽 (현재 추가된 칸)

		//빠진칸이 고쳐야할 칸이었다면
		if (arr[left])
			//제거
			count--;

		//추가된칸이 고쳐야할 칸이라면
		if (arr[right])
			//추가
			count++;

		//최솟값 갱신
		if (min > count)
			min = count;
	}

	cout << min;

	return 0;
}
