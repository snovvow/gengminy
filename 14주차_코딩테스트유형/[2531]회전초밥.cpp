#include <iostream>
#include <vector>
using namespace std;

int sushi[300001];
bool check[3001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, d, k, c;

    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }

    int result_max = 0;
    //쿠폰 유무
    int coupon = 1;

    //중복개수
    int dup = 0;

    for (int i = 0; i < N; i++) {
        dup = 0;
        coupon = 1;
        for (int j = i; j < i + k; j++) {
            if (check[sushi[j % N]]) {
                dup++;
            }
            else check[sushi[j % N]] = true;

            if (sushi[j % N] == c) coupon = 0;
        }

        result_max = max(result_max, k - dup + coupon);
        
        for (int i = 0; i < 3001; ++i)
            check[i] = false;
    }

    cout << result_max;

    return 0;
}
