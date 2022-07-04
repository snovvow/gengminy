#include <iostream>
#include <string>
#include <vector>

using namespace std;


string find(string s) {
    int len = s.length();

    //초기 상태 -1
    int status = -1;

    for (int i = 0; i < len; ++i) {
        
        //초기 상태
        if (status == -1) {
            if (s[i] == '0')
                status = 0; //0으로 시작하면 status 0으로 분기
            if (s[i] == '1')
                status = 1; //1로 시작하면 status 1으로 분기
        }
        //0으로 시작하는 패턴일때 뒤에 반드시 1이 나와야함
        else if (status == 0) {
            //01
            if (s[i] == '1')
                status = -1; //이후에 어떤 값이 나오더라도 가능
            //00
            else
                return "NO";
        }
        //1
        else if (status == 1) {
            //10
            if (s[i] == '0')
                status = 2;
            //11
            else
                return "NO";
        }
        else if (status == 2) {
            //100
            if (s[i] == '0')
                status = 3;
            //101
            else
                return "NO";
        }
        else if (status == 3) {
            //100+
            if (s[i] == '0')
                continue;
            //100+1
            else
                status = 4;
        }
        else if (status == 4) {
            //100+11
            if (s[i] == '1')
                status = 5;
            //100+10
            else
                status = 0;
        }
        else if (status == 5) {
            //100+1+
            if (s[i] == '1')
                continue;
            //100+110
            else
                status = 6;
        }
        else if (status == 6) {
            //100+1+ 01
            if (s[i] == '1')
                status = -1;
            //100+1+00+
            else
                status = 3;
        }
    }

    if (status == -1 || status == 4 || status == 5) return "YES";
    return "NO";
}

int main(void) {
    int N;
    string input;

    cin >> N;
    while (N--) {
        cin >> input;

        cout << find(input) << endl;
    }
    return 0;
}
