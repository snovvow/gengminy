#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
char arr[11];
bool isVisit[11];
bool found = false;
vector<int> cur;

bool isValid() {
	for (int i = 0; i < k; ++i) {
		if (arr[i] == '<') {
			if (cur[i] >= cur[i + 1])
				return false;
		}
		else {
			if (cur[i] <= cur[i + 1])
				return false;
		}
	}
	return true;
}

void backtracking(int depth, bool high) {
	if (!found && depth == k + 1 && isValid()) {
		found = true;
		for (int i = 0; i < k + 1; ++i)
			cout << cur[i];

		for (int i = 0; i < 11; ++i)
			isVisit[i] = false;
		cout << endl;
	}
	else if (!found) {
		if (!high)
			for (int i = 0; i < 10; ++i) {
				if (!isVisit[i]) {
					isVisit[i] = true;
					cur.push_back(i);
					backtracking(depth + 1, high);
					isVisit[i] = false;
					cur.pop_back();
				}
			}
		else
			for (int i = 9; i >= 0; --i) {
				if (!isVisit[i]) {
					isVisit[i] = true;
					cur.push_back(i);
					backtracking(depth + 1, high);
					isVisit[i] = false;
					cur.pop_back();
				}
			}
	}
}

int main(void) {
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> arr[i];
	}

	
	backtracking(0, true);
	found = false;
	while (!cur.empty())
		cur.pop_back();
	backtracking(0, false);
}
