#include <iostream>
#include <cstdio>
using namespace std;

int parent[1000001];

int find(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b)
		parent[a] = b;
	else if (a < b)
		parent[b] = a;
}

int main(void) {
	int T, N, K, M, a, b;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Scenario %d:\n", t);
		scanf("%d", &N);
		for (int i = 0; i <= N; ++i)
			parent[i] = i;

		scanf("%d", &K);
		//친구 관계 입력
		for (int i = 0; i < K; ++i) {
			scanf("%d %d", &a, &b);
			merge(a, b);
		}

		//구하는 경로 탐색
		scanf("%d", &M);
		for (int i = 0; i < M; ++i) {
			scanf("%d %d", &a, &b);
			if (find(a) == find(b))
				printf("1\n");
			else
				printf("0\n");
		}

		if (t != T) printf("\n");
	}
}

//로직은 정확하지만, cin cout 의 시간 소요로 인한 시간초과 발생