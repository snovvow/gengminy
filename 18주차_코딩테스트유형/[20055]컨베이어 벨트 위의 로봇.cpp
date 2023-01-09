#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, K;
int a[201];
bool onBoard[201];

int getCheckCount(void) {
	int cnt = 0;
	for (int i = 1; i <= 2 * N; i++)
		if (a[i] <= 0)
			cnt++;
			
	return cnt;
}

int main() {
	cin >> N >> K;

	int front = 1;
	int back = N;
	int checkCount = 0;
	int limit = 2 * N;
	int level = 0;

	queue<int> q;

	for (int i = 1; i <= limit; i++) {
		cin >> a[i];
	}

	while (1) {
		level++;

		//1. 컨베이어 벨트 회전
		front--;
		if (front < 1)
			front = limit;
		back--;
		if (back < 1)
			back = limit;

		// 2. 컨베이어 위의 로봇들  이동
		// 로봇 갯수 (루프 횟수)
		int t = q.size();
		for (int i = 0; i < t; i++) {
			int cur = q.front();
			onBoard[cur] = false;
			q.pop();

			//제자리에 서있는데 끝에 도달
			if (cur != back) {

				//다음 칸으로 이동
				int next = cur % limit + 1;
				if (!onBoard[next] && a[next] > 0) {
					a[next]--;

					//이동하여 끝에 도달하지 않으면
					if (next != back) {
						onBoard[next] = true;
						q.push(next);
					}
				}
				//움직이지 않음
				else {
					onBoard[cur] = true;
					q.push(cur);
				}
			}
		}


		// 3. 올리는 위치에 탑승
		if (!onBoard[front] && a[front] > 0) {
			onBoard[front] = true;
			a[front]--;
			q.push(front);
		}

	//	cout << front << " " << back << " " << getCheckCount() << " " << level << endl;

		// 4. 과정 종료
		if (getCheckCount() >= K)
			break;
	}


	cout << level << endl;
}
