#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main(void)
{
	int N, x, y, count, size, max;
	scanf("%d", &N);
	vector<pair<int, int>> line;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &x, &y);
		line.push_back(make_pair(x, 1));
		line.push_back(make_pair(y, -1));
	}
	
	sort(line.begin(), line.end(), cmp);
	max = 0;
	count = 0;
	size = line.size();
	for (int i = 0; i < size; ++i)
	{
		count += line[i].second;
		if (count > max)
			max = count;
	}
	printf("%d\n", max);
	return 0;
}

/*

각 선분마다 하나씩 비교하면 최악의 경우 O(n^2) 로 시간초과
-> 선분의 시작을 +1, 끝을 -1 로 지정하여 최대값 도출

*/