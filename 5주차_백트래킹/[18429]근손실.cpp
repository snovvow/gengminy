#include <iostream>
using namespace std;

int kit[8];
int N, K;
int cnt;
bool isVisit[8];
void backtracking(int val, int depth, int total) {
	if (total < 500)
		return;
	if (depth == N)
		cnt++;
	for (int i = 0; i < N; ++i)
	{
		if (!isVisit[i])
		{
			isVisit[i] = true;
			backtracking(i, depth + 1, total + kit[i] - K);
			isVisit[i] = false;
		}
	}
}
int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> kit[i];

	for (int i = 0; i < N; ++i) {
		isVisit[i] = true;
		backtracking(i, 1, 500);
		isVisit[i] = false;
	}
	cout << cnt;
}
