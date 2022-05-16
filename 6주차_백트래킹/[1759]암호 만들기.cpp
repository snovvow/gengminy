#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> alpha;
bool isVisit[15];

bool isValid() {
	int mo = 0;
	int ja = 0;

	for (int i = 0; i < C; ++i) {
		if (isVisit[i]) {
			if (alpha[i] == 'a' || alpha[i] == 'e' ||
				alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
				mo++;
			else
				ja++;
		}
	}

	if (mo >= 1 && ja >= 2)
		return true;
	return false;
}

void backtracking(int index, int depth) {
	if (depth == L && isValid()) {
		for (int i = 0; i < C; ++i) {
			if (isVisit[i]) {
				cout << alpha[i];
			}
		}
		cout << endl;
	}
	else {
		for (int i = index + 1; i < C; ++i) {
			isVisit[i] = true;
			backtracking(i, depth + 1);
			isVisit[i] = false;
		}
	}
}

int main(void) {
	char input;

	cin >> L >> C;

	for (int i = 0; i < C; ++i) {
		cin >> input;
		alpha.push_back(input);
	}
	sort(alpha.begin(), alpha.end());
	backtracking(-1, 0);
}
