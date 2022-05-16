#include <iostream>
#include <string>

using namespace std;

int R, C, T;
int MAX = 0;
string map[101];
bool isVisit[100][100];
int nc[] = {0, 0, 1, -1};
int nr[] = {1, -1, 0, 0};

void backtracking(int col, int row, int depth, int count){
    if (depth == T){
        if (count > MAX)
            MAX = count;
    } else {
        for (int k = 0; k < 4; ++k){
            int nCol = col + nc[k];
            int nRow = row + nr[k];

            if (0 <= nCol && nCol < R && 0 <= nRow && nRow < C 
            && map[nCol][nRow] != '#'){
                if (map[nCol][nRow] == 'S' && !isVisit[nCol][nRow]){
                    isVisit[nCol][nRow] = true;
                    backtracking(nCol, nRow, depth + 1, count + 1);
                    isVisit[nCol][nRow] = false;
                } else
                    backtracking(nCol, nRow, depth + 1, count);
            }
        }
    }
}

int main(void){
    pair<int, int> G;
    cin >> R >> C >> T;
    for (int i = 0 ; i < R; ++i)
        cin >> map[i];

    for (int i = 0; i < R; ++i){
        for (int j = 0; j < C; ++j){
            if (map[i][j] == 'G')
                G = make_pair(i, j);
            else if (map[i][j] == '#')
                isVisit[i][j] = true;
        }
    }
    backtracking(G.first, G.second, 0, 0);
    cout << MAX << endl;
}