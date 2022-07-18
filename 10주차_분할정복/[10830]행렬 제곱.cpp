/*
*   [BOJ]행렬 제곱 / 골드4
*   https://www.acmicpc.net/problem/10830
*/

#include <iostream>
using namespace std;

int matrix[5][5], ans[5][5];
int N;
long long B;

void matrixSquare(int a[5][5], int b[5][5]) {
	int t[5][5];

	//제곱
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int tmp = 0;

			for (int k = 0; k < N; ++k) {
				tmp += (a[i][k] * b[k][j]);
			}

			t[i][j] = tmp;
		}
	}

	//나누기 1000 + 배열에 삽입
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			a[i][j] = t[i][j] % 1000;
		}
	}
}

int main(void) {

	cin >> N >> B;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> matrix[i][j];
		}
		ans[i][i] = 1; //단위행렬 처리
	}	

	while (B) {
		//홀수면 한번 더 곱해줌
		if (B % 2 == 1) {
			matrixSquare(ans, matrix);
		}
		matrixSquare(matrix, matrix);
		B /= 2;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

//A^n = A^(n/2) * A^(n/2) 로 분할 할 수 있다