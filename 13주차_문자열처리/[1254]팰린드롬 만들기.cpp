//[BOJ] 팰린드롬 만들기 / 실버2 https://www.acmicpc.net/problem/1254

#include <iostream>
#include <string>

using namespace std;

bool isSymmetry(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right])
            return false;

        left++;
        right--;
    }
    return true;
}

int main(void){
    string str;
    int len, mid, ans;

    cin >> str;
    len = str.length();
    mid = len / 2; //pivot
    ans = len * 2 - 1;

    for (int i = 0; i < len; ++i) {
        if (isSymmetry(str.substr(i, len - i))){
            ans = len + i;
            break;
        }
    }

    cout << ans << endl;

    //pivot 기준으로 좌 우가 동일하면 팰린드롬
    return 0;
}