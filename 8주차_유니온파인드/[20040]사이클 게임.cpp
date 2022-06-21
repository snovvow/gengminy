#include <iostream>
#include <cstdio>
using namespace std;

int parent[500000];

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
	int N, M, a, b, t;
	scanf("%d %d", &N, &M);


	//초기화
	for (int i = 0; i < N; ++i)
		parent[i] = i;
	t = 0;

	for (int i = 0; i < M; ++i) {
		t++;
		scanf("%d %d", &a, &b);

		if (find(a) == find(b)) {
			printf("%d\n", t);
			return 0;
		}
		merge(a, b);
	}
	printf("0\n");
}

//로직은 맞았지만 출력에서 실수