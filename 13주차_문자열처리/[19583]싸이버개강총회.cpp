//[BOJ] 싸이버개강총회 / 실버2 https://www.acmicpc.net/problem/19583

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

bool isPrevious(string a, string b) {
    int h1 = (a[0] - '0') * 10 + (a[1] - '0');
    int m1 = (a[3] - '0') * 10 + (a[4] - '0');

    int h2 = (b[0] - '0') * 10 + (b[1] - '0');
    int m2 = (b[3] - '0') * 10 + (b[4] - '0');

    if (h1 < h2){
        return true;
    } else if (h1 == h2 && m1 <= m2){
        return true;
    }
    return false;
}

map<string, string> table;
map<string, string>::iterator it;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S, E, Q;
    int cnt = 0;
    string time, name;


    //시간 입력후 분할

    cin >> S >> E >> Q;

    while (!cin.eof()) {
        cin >> time >> name;

        it = table.find(name);
        if (isPrevious(time, S) && it == table.end()) {
            //시작 시간보다 입장이 빠르고 테이블에 없으면 추가
            table.insert(make_pair(name, time));
        }

        if (isPrevious(E, time) && isPrevious(time, Q)
            && it != table.end()){
            //끝난 시간과 스트리밍 종료 시간 사이에 있고 테이블에 있으면 제거 후 카운트
            cnt++;
            table.erase(it);
        }
    }

    cout << cnt << endl;
    return 0;
}