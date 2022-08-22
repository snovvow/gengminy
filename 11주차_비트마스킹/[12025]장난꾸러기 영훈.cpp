/**
 * [12025]장난꾸러기 영훈.CPP
 * 골드5
 * 2022-08-22
 * https://www.acmicpc.net/problem/12025
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string input;
long long N, M = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> input >> N;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '1' || input[i] == '6') {
			input[i] = '1';
			M *= 2;
		}
		else if (input[i] == '2' || input[i] == '7') {
			input[i] = '2';
			M *= 2;
		}
	}
	if (N > M || N < 0) {
		cout << -1 << "\n";
	}
	else {
		N -= 1;
		for (int i = input.length() - 1; i >= 0; i--) {
			if (input[i] == '1') {
				if (N % 2) {
					input[i] = '6';
				}
				N /= 2;
			}
			else if (input[i] == '2') {
				if (N % 2) {
					input[i] = '7';
				}
				N /= 2;
			}
		}
		cout << input << "\n";
	}

	return 0;
}