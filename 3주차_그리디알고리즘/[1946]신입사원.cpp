#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp1(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main(void)
{
	int T, N, x, y, count, min;
	vector<pair<int, int>> man;
	cin >> T;
	while (T--)
	{
		man.clear();
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> x >> y;
			man.push_back(make_pair(x, y));
		}
		sort(man.begin(), man.end(), cmp1);
		count = N;
		min = man[0].second;
		for (int i = 1; i < N; ++i)
		{
			if (man[i].second < min)
				min = man[i].second;
			else
				count--;
		}
		cout << count << endl;
	}

	return 0;
}