#include <iostream>
#include <cstdio>
using namespace std;

int parent[300001];

int gFind(int x){
    if (parent[x] == x){
        return x;
    }
    return parent[x] = gFind(parent[x]);
}

void gUnion(int x, int y){
    x = gFind(x);
    y = gFind(y);

    if (x == y) return ;
    parent[y] = x;
}

int main(void){
    int N, a, b;
    scanf("%d", &N);

    /* 자기 자신으로 부모 노드 설정 (초기화) */
    for (int i = 1; i <= N; ++i){
        parent[i] = i;
    }

    /* 입력 */
    for (int i = 1; i <= N - 2; ++i){
        scanf("%d %d", &a, &b);
        gUnion(a, b);
    }

    /* 부모 루트 노드가 다른 두 노드 출력 */
    a = gFind(1);
    for (int i = 2; i <= N; ++i){
        b = gFind(i);
        if (a != b){ 
            printf("%d %d\n", a, b);
            break;
        }
    }
    return 0;
}