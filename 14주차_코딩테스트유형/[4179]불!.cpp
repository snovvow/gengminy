#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define INF 99999999

int R, C;
vector<string> map;
bool visit[1001][1001];
int firemap[1001][1001];

int main(void) {
    string input;

    queue<vector<int> > q1; //jihoon
    queue<vector<int> > q2; //fire
    
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> input;
        map.push_back(input);
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'J') {
                visit[i][j] = true;
                q1.push({i, j, 0});
            }
            else if (map[i][j] == 'F') {
                firemap[i][j] = 0;
                q2.push({i, j, 0});
            }
            else {
                firemap[i][j] = INF;
            }
        }
    }

    int nc[] = {1, -1, 0, 0};
    int nr[] = {0, 0, 1, -1};
    
    //불지도 먼저 만듬
    while(!q2.empty()) {
        int size = q2.size();
        for (int s = 0; s < size; s++) {
            int col = q2.front()[0];
            int row = q2.front()[1];
            q2.pop();

            for (int i = 0; i < 4; i++) {
                int ncol = nc[i] + col;
                int nrow = nr[i] + row;

                if (0 <= ncol && ncol < R && 0 <= nrow && nrow < C) {
                    if (map[ncol][nrow] != '#' && firemap[ncol][nrow] > firemap[col][row] + 1){
                        firemap[ncol][nrow] = firemap[col][row] + 1;
                        q2.push({ncol, nrow});
                    }
                } 
            }
        }
    }


    //지훈 이동
    while (!q1.empty()) {
        int col = q1.front()[0];
        int row = q1.front()[1];
        int cnt = q1.front()[2];
        q1.pop();

        for (int i = 0; i < 4; i++) {
            int ncol = nc[i] + col;
            int nrow = nr[i] + row;

            if (0 <= ncol && ncol < R && 0 <= nrow && nrow < C) {
                if (map[ncol][nrow] != '#' && !visit[ncol][nrow] && firemap[ncol][nrow] > cnt + 1){
                    visit[ncol][nrow] = true;
                    q1.push({ncol, nrow, cnt + 1});
                }
            } //범위 밖이면 탈출 
            else {
                cout << cnt + 1 << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}