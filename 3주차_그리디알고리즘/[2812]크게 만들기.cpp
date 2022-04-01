#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	vector<char> st;
	string input;
	int N, K, cnt;
	cin >> N >> K;
	cin >> input;
	cnt = K;

	/* initialize */
	st.push_back(input[0]);
	for (int i = 1; i < N; ++i)
	{
		while (cnt > 0 && st.size() > 0 && st.back() < input[i])
		{
			st.pop_back();
			cnt--;
		}
		st.push_back(input[i]);
	}

	/*
	5 2 54321 의 경우 위 조건을 만족하지 않아 예외
	남은 횟수만큼 무조건 삭제
	*/
	while (cnt > 0)
	{
		st.pop_back();
		cnt--;
	}

	int len = st.size();
	for (int i = 0; i < len; ++i)
	{
		cout << st[i];
	}
}
