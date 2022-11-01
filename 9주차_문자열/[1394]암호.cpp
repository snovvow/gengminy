#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    string s, pw;
    //오버플로우 방지
    unsigned long long cnt = 0;
    //n 제곱 저장
    unsigned long long tmp = 1;
    cin >> s >> pw;

    int k = s.length();
    int n = pw.length();

    for (int i = n - 1; i >= 0; i--) {
        //패스워드의 인덱스 구함
        int idx = s.find(pw[i]);
        cnt = (cnt + tmp * (idx + 1)) % 900528;
        tmp = tmp * k % 900528;
    }
    
    cout << cnt << endl;
}
