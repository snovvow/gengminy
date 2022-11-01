#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;

    //홀수이면 패스를 한번씩 받을 수 없음
    if (N == 1)
        cout << 1 << "\n";
    else if (N % 2)
        cout << -1 << "\n";
    else {
        for (int i = 0; i < N; i++) {
            //첫번째 사람이 N이 써진 카드를 뽑아서 자신에게 다시 차례가 올 수 있음
            if (!(i % 2)) {
                cout << N - i << " ";
            } else {
                cout << i << " ";
            }
        }
    }
}
