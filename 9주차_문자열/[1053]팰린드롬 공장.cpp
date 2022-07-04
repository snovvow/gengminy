#include <iostream>
#include <string>
#define INF 10000000
using namespace std;

int dp[51][51];
string str;

void swap(char &s1, char &s2){
    char tmp = s1;
    s1 = s2;
    s2 = tmp;
}

void init(void){
    for (int i = 0; i < 51; ++i)
        for (int j = 0; j < 51; ++j)
            dp[i][j] = -1;
}

int dfs(int left, int right){
    if (left >= right)
        return 0;
    
    int &ret = dp[left][right];
    if (ret != -1)
        return ret;

    
    ret = INF;

    //현재 검사하는 칸이 대칭이면 다음으로
    if (str[left] == str[right])
        ret = min(ret, dfs(left + 1, right - 1));

    //1번 연산 문자를 삽입
    ret = min(ret, 1 + dfs(left + 1, right));
    //2번 연산 문자를 교환
    ret = min(ret, 1 + dfs(left + 1, right - 1));
    //3번 연산 문자를 삭제
    ret = min(ret, 1 + dfs(left, right - 1));

    return ret;
}

int main(){
    cin >> str;
    int len = str.length();
    int result = INF;

    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            //i == j 이면 4번 연산으로 바꾸지 않는 경우
            //i != j 이면 4번 연산을 쓴 경우 swap
            swap(str[i], str[j]);

            //dp 및 상태 초기화
            int left = 0;
            int right = len - 1;
            init();

            int ret = dfs(left, right);
            //4번 연산이 발생하면 1 더함
            if (i != j)
                ret++;
            result = min(ret, result);

            swap(str[i], str[j]);
        }
    }

    cout << result;
}
