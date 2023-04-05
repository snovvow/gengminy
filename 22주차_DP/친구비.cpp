//골드4

#include <iostream>
#include <vector>
using namespace std;

int N, M, k;
int cost[10001]; //친구비용
int parent[10001]; //부모 노드 번호

int find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);
    if (x != y) {
        if (cost[x] > cost[y]) 
	        parent[x] = y;
        else
            parent[y] = x;
    }
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int sum = 0;

    cin >> N >> M >> k;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        cin >> cost[i];
    }

    int v, w;
    for (int i = 0; i < M; i++) {
        cin >> v >> w;
        Union(v, w);
    } // 같은 집합으로 만듬

    for (int i = 1; i <= N; i++) {
        int p = find(i);
        // 0번(자신)과 친구가 아니면 집합을 합치고 값을 더함
        if (p != parent[0]) {
            sum += cost[p];
            Union(0, i);
        }
    }

    if (sum > k)
        cout << "Oh no" << endl;
    else
        cout << sum << endl;

}
