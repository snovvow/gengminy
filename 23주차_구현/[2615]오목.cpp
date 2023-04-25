#include <iostream>
#include <queue>
#define SIZE 19
using namespace std;

int ans;
int arr[20][20];

int x[] = {1, 1, 1, 0};
int y[] = {-1, 0, 1, 1};

//dfs depth == 5 일때만 정답
int find_answer(int cy, int cx, int dol, int cnt, int dir) {
    int nx = cx + x[dir];
    int ny = cy + y[dir];

    if (0 <= ny && ny < SIZE && 0 <= nx && nx < SIZE && arr[ny][nx] == dol) {
        return find_answer(ny, nx, dol, cnt + 1, dir);
    }
    return cnt;
}

int main() {
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(0);


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 4; k++) {
                if (arr[i][j] != 0 && find_answer(i, j, arr[i][j], 1, k) == 5) {
                    int px = j - x[k];
                    int py = i - y[k];
                    if (!(0 <= py && py < SIZE && 0 <= px && px < SIZE)
                        || (0 <= py && py < SIZE && 0 <= px && px < SIZE
                        && arr[py][px] != arr[i][j])) {
                        cout << arr[i][j] << endl;
                        cout << i + 1 << " " << j + 1 << endl;
                        exit(0);
                    }
                }
            }
        }
    }
    cout << 0 << endl;
}