#include <iostream>
#include <vector>
#include <string>

using namespace std;
int MAX, R, C;
string map[20];
bool isVisit[20][20];
bool alphaVisit[26];
int nr[] = {0, 0, 1, -1};
int nc[] = {1, -1, 0, 0};

void backtracking(int r, int c, int depth){
    if (depth > MAX)
        MAX = depth;
    for (int i = 0; i < 4; ++i){
        int nRow = r + nr[i];
        int nCol = c + nc[i];
        int alphaNum = map[nRow][nCol] - 'A';
        if (0 <= nRow && nRow < R && 0 <= nCol && nCol < C && !isVisit[nRow][nCol]){
            if (!alphaVisit[alphaNum] && map[r][c] != map[nRow][nCol]){
                isVisit[nRow][nCol] = true;
                alphaVisit[alphaNum] = true;
                backtracking(nRow, nCol, depth + 1);
                isVisit[nRow][nCol] = false;
                alphaVisit[alphaNum] = false;
            }
        }
    }
}

int main(){
    cin >> R >> C;
    for (int i = 0; i < R; ++i){
        cin >> map[i];
    }
    alphaVisit[map[0][0] - 'A'] = true;
    backtracking(0, 0, 1);
    cout << MAX << endl;
}
