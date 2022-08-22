/**
 * [1062]가르침.CPP
 * 골드4
 * 2022-08-22
 * https://www.acmicpc.net/problem/1062
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int words[50];
int N, K;
int learned;
int picked;
int resultmax;

void backtracking(int n) {

	/* 탈출조건 : K개의 단어를 배움 */
	if (picked == K) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if ((words[i] & learned) == words[i]) {
				cnt++;
			}
			if (cnt > resultmax) {
				resultmax = cnt;
			}
		}
		return;
	}
	
	for (int i = n; i < 26; i++) {
		/* 아직 안배운거 */
		int toLearn = 1 << i;
		if (!(learned & toLearn)) {
			learned |= toLearn;
			picked++;
			backtracking(i);
			learned &= ~toLearn;
			picked--;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	string word;

	cin >> N >> K;

	/* a, n, t, i ,c -> 최소 5개 필요 */
	if (K < 5) {
		cout << 0;
	} else if (K == 26) {
		cout << N;
	} else {
		for (int i = 0; i < N; ++i) {
			cin >> word;

			int pos = 0;
			/* int -> 32bit 이므로 26개의 알파벳 저장 */
			for (int j = 0; j < word.length(); ++j) {
				pos |= 1 << (word[j] - 'a');
			}
			/* 존재하는 알파벳 비트로 저장 */
			words[i] = pos;
		}

		learned |= 1 << ('a' - 'a');
		learned |= 1 << ('n' - 'a');
		learned |= 1 << ('t' - 'a');
		learned |= 1 << ('i' - 'a');
		learned |= 1 << ('c' - 'a');
		picked = 5;
		backtracking(0);

		cout << resultmax;
	}

	return 0;
}
