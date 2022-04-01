#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int input[1000];

int main(void)
{
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &input[i]);

	sort(input, input + N);
	
	int ans = 1;
	for (int i = 0; i < N; ++i)
	{
        /* 현재 올려야하는 추가
        현재 정답보다 크다면 수평을 맞추지 못함 */
		if (input[i] > ans)
			break;
		ans += input[i];
	}
	printf("%d\n", ans);
}
