/**
 * [18233]러버덕을 사랑하는 모임.cpp
 * 실버1
 * 2022-08-22
 * https://www.acmicpc.net/problem/18233
 */

#include <iostream>
#include <vector>
using namespace std;

int result[21];
bool found;
int N, P, E;
vector<pair<int, int>> member;
vector<int> memberNum;

void backtracking(int n) {

	if (found)
		return;
	/* 인원이 P명이 되면 검사 수행 */
	if (memberNum.size() == P) {
		int min = 0;
		int max = 0;
		for (int i = 0; i < P; i++) {
			min += member[memberNum[i]].first;
			max += member[memberNum[i]].second;
		}
		
		/* 분배 가능 */
		if (min <= E && E <= max) {
			/* 최소 만큼 우선 분배 */
			for (int i = 0; i < P; i++) {
				result[memberNum[i]] = member[memberNum[i]].first;
			}
			/* 최소만큼 분배하고 남은 나머지 */
			int rem = E - min;
			for (int i = 0; i < P; i++) {
				int cur = memberNum[i];
				int curRem = member[cur].second - member[cur].first;

				if (curRem <= rem) {
					result[cur] += (member[cur].second - member[cur].first);
					rem -= (member[cur].second - member[cur].first);
				}
				else {
					result[cur] += rem;
					rem = 0;
				}
			}


			/*  */
			for (int i = 0; i < N; ++i) {
				cout << result[i] << " ";
			}
			found = true;
			return;
		}
	}

	for (int i = n + 1; i < N; ++i) {
		memberNum.push_back(i);
		backtracking(i);
		memberNum.pop_back();
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	int x, y;

	cin >> N >> P >> E;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		member.push_back(make_pair(x, y));
	}

	for (int i = 0; i < N; i++) {
		memberNum.push_back(i);
		backtracking(i);
		memberNum.pop_back();
	}

	if (!found)
		cout << -1;

	return 0;
}
