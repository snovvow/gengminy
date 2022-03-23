#include <iostream>
#include <vector>
using namespace std;

vector<int> computer[101];
int cnt = 0;
bool isVisit[101];

void DFS(int N)
{
	int len = computer[N].size();
	isVisit[N] = true;
	for (int i = 0; i < len; ++i)
	{
		if (!isVisit[computer[N][i]])
		{
			cnt++;
			DFS(computer[N][i]);
		}
	}
}

int main(void)
{
	int N, T, s, e;
	cin >> N >> T;
	while (T--)
	{
		cin >> s >> e;
		computer[s].push_back(e);
		computer[e].push_back(s);
	}

	DFS(1);
	cout << cnt << endl;
}