#include <iostream>
#include <vector>
using namespace std;

int N;
int power[20][20] = {0,};
int MIN = 10000;
bool picked[20] = { 0, };
void backtracking(int depth, int lastNumber) {
	if (depth == N / 2) {
		int startPower = 0;
		int linkPower = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (picked[i] && picked[j]) {
					startPower += power[i][j];
				}
				else if (!picked[i] && !picked[j]) {
					linkPower += power[i][j];
				}
			}
		}
		int result = abs(startPower - linkPower);
		if (result < MIN)
			MIN = result;
		//MIN = 
	}

	for (int i = lastNumber; i < N; ++i) {
		if (!picked[i]) {
			picked[i] = true;
			backtracking(depth+1, i);
			picked[i] = false;
		}
	}
}
int main(void) {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> power[i][j];
		}
	}
	backtracking(0,0);
	cout << MIN << endl;
}