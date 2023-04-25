#include <iostream>
using namespace std;

int day = 14;
int price[15];
int main() {
    int total;
    cin >> total;

    int junhyeon_money = total;
    int junhyeon_stock = 0;
    int sungmin_money = total;
    int sungmin_stock = 0;

    int ascend = 0; // 연속으로 오른 날
    int descend = 0; // 연속으로 떨어진 날
    for (int i = 0; i < day; i++) {
        cin >> price[i];

        junhyeon_stock += junhyeon_money / price[i];
        junhyeon_money -= (junhyeon_money / price[i]) * price[i]; // 산 개수

        if (i != 0 && price[i - 1] < price[i])
            ascend++;
        else
            ascend = 0;
        if (i != 0 && price[i - 1] > price[i])
            descend++;
        else
            descend = 0;
        
        if (ascend >= 3) {
            sungmin_money += sungmin_stock * price[i];
            sungmin_stock = 0;
        }
        if (descend >= 3) {
            sungmin_stock += sungmin_money / price[i];
            sungmin_money -= (sungmin_money / price[i]) * price[i]; // 산 개수
        }
    }

    int junhyeon_total = junhyeon_money + junhyeon_stock * price[day - 1];
    int sungmin_total = sungmin_money + sungmin_stock * price[day - 1];

    if (junhyeon_total > sungmin_total) 
        cout << "BNP" << endl;
    else if (junhyeon_total < sungmin_total)
        cout << "TIMING" << endl;
    else
        cout << "SAMESAME" << endl;
}