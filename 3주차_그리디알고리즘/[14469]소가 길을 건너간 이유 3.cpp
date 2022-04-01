#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main(void)
{
	int N, x, y;
	int result = 0;
	cin >> N;
	vector<pair<int, int>> cow;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		cow.push_back(make_pair(x, y));
	}

	sort(cow.begin(), cow.end(), cmp);

	for (int i = 0; i < N; ++i)
	{
		/* 도착시간보다 걸린 시간이 더 길면 보정 */
		if (result < cow[i].first)
			result = cow[i].first + cow[i].second;
		/* 도착과 동시에 검문을 받으면 그냥 더하기 */
		else
			result += cow[i].second;
	}
	cout << result;

	return 0;
}