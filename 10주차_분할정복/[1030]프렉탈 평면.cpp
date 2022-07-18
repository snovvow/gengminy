/*
*   [BOJ]프렉탈 평면 / 골드3
*   https://www.acmicpc.net/problem/1030
*/

#include <iostream>
using namespace std;

int mapSize, s, N, K;

int pow(int n, int k) {
	int ret = 1;
	while (k--) {
		ret *= n;
	}
	return ret;
}

int getColor(int r, int c) {
	int left = (N - K) / 2;
	int fragment = mapSize / N;

	while (fragment) {
		if (left <= r / fragment && r / fragment < N - left
			&& left <= c / fragment && c / fragment < N - left)
			return 1;
		r %= fragment;
		c %= fragment;
		fragment /= N;
	}
	return 0;
}

int main(void) {
	int R1, R2, C1, C2;
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	mapSize = pow(N, s);

	for (int i = R1; i <= R2; ++i) {
		for (int j = C1; j <= C2; ++j) {
			cout << getColor(i, j);
		}
		cout << endl;
	}
}