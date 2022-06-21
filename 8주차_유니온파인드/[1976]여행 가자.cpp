#include <iostream>
using namespace std;

int parent[201];

int find(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main(void) {
	int N, M, a;
	cin >> N >> M;

	/* 초기화 */
	for (int i = 0; i <= N; ++i) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> a;
			if (a == 1) {
				merge(i, j);
			}
		}
	}

	int ans = -1;
	for (int i = 1; i <= M; ++i) {
		cin >> a;
		a = find(a);
		if (ans == -1)
			ans = a;
		else if (ans != a) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}