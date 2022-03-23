#include <iostream>
#include <queue>
using namespace std;

int N;
int map[21][21];
bool isVisit[21][21];
vector<int> shark;
queue<vector<int>> q;
int cpos[] = { -1, 0, 0, 1 };
int rpos[] = { 0, -1, 1, 0 };

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
				shark = { i, j, 2, 0, 0 };
			// {col, row, size, feed, time}
		}
	}

	int col, row, size, feed, time;

	while (1)
	{
		col = shark[0];
		row = shark[1];
		size = shark[2];
		feed = shark[3];
		time = shark[4];

		/* 지도 방문 초기화 및 이동할수 있는 칸 조작 */
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (map[i][j] <= size)
					isVisit[i][j] = false;
				else
					isVisit[i][j] = true;
			}
		}

		q.push({ col, row, 0 });


		/* 다음 물고기 좌표까지의 BFS 실행 */

		/* 우선순위가 높은 물고기를 선택하기 위한 배열 */
		vector<int> prime = { 100, 100, 100 };
		while (!q.empty())
		{
			int qCol, qRow, qTime, nc, nr;
			qCol = q.front()[0];
			qRow = q.front()[1];
			qTime = q.front()[2];
			q.pop();

			/* 9가 아닐때 조건 안달아서 2시간 삽질함 ;;; */
			if (map[qCol][qRow] != 9 && 0 < map[qCol][qRow] && map[qCol][qRow] < size)
			{
				if (prime[2] == 100)
					prime = { qCol, qRow, qTime };
				//최초로 선택
				else if (prime[2] == qTime)
				{
					if (qCol < prime[0]) //더 위에 있는 것
						prime = { qCol, qRow, qTime };
					else if (qCol == prime[0] && qRow < prime[1]) //col이 같으면 더 왼쪽것
						prime = { qCol, qRow, qTime };
				}
				else
					break;
			}

			for (int i = 0; i < 4; ++i)
			{
				nc = qCol + cpos[i];
				nr = qRow + rpos[i];
				if (0 <= nc && nc < N && 0 <= nr && nr < N && !isVisit[nc][nr])
				{
					isVisit[nc][nr] = true;
					q.push({ nc, nr, qTime + 1 });
				}
			}
		}

		/* 다음 물고기를 찾지 못한 경우*/
		if (prime[2] == 100)
			break;
		else
		{
			while (!q.empty())
				q.pop();

			feed++;
			if (size <= feed)
			{
				size++;
				feed = 0;
			}
			shark = { prime[0], prime[1], size, feed, time + prime[2] };
			map[col][row] = 0;
			map[prime[0]][prime[1]] = 9;
		}

	}

	cout << shark[4] << endl;
}