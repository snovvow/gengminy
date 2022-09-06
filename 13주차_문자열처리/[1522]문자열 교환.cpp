//[BOJ] 문자열 교환 / 골드5 https://www.acmicpc.net/problem/1522

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int len = str.length();
    int cnt = 0; //a의 개수

    for (int i = 0; i < len; i++) {
        if (str[i] == 'a')
            cnt++;
    }

    str += str.substr(0, cnt); //원형으로 돈다 했으니 뒤에 붙여줌

    len = str.length();
    int min = str.length();

    for (int i = 0; i < len - cnt; i++) {
        int change = 0;
        for (int j = i; j < i + cnt && j < len; j++) {
            if (str[j] == 'b')
                change++;
        }

        if (change < min)
            min = change;
    }

    cout << min << endl;

    return 0;
}