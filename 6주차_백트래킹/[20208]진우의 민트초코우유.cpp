#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
int MAX = 0;
int map[10][10];
bool isVisit[10];
pair<int ,int> home;
vector<pair<int, int> > milk;
int nc[] = {0, 0, 1, -1};
int nr[] = {1, -1, 0, 0};

bool canGoHome(int col, int row, int health){
    if (abs(col - home.first) + abs(row - home.second) <= health)
        return true;
    return false;
}

void backtracking(int col, int row, int depth, int health){
    if (health >= abs(col - home.first) + abs(row - home.second)){
        if (depth > MAX)
            MAX = depth;
    }
    if (depth == milk.size())
        return ;
    for (int i = 0; i < milk.size(); ++i){
        int nCol = milk[i].first;
        int nRow = milk[i].second;

        int nDist = abs(nCol - col) + abs(nRow - row);

        if (!isVisit[i] && health >= nDist){
            isVisit[i] = true;
            backtracking(nCol, nRow, depth + 1, health - nDist + H);
            isVisit[i] = false;
        }
    }
}

int main(void){
    cin >> N >> M >> H;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> map[i][j];
            if (map[i][j] == 1)
                home = make_pair(i, j);
            if (map[i][j] == 2)
                milk.push_back(make_pair(i, j));
        }
    }
    backtracking(home.first, home.second, 0, M);
    cout << MAX << endl;
}
