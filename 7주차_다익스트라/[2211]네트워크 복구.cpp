#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

int N, M;
vector<pair<int, int> > edge[1001];
vector<int> dist(1001);
vector<int> prevNode(1001);

int main(void){
    int a, b, c;
   
    cin >> N >> M;
    for (int i = 0; i < M; ++i){
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c)); //a->b 비용 c
        edge[b].push_back(make_pair(a, c)); //양방향 간선
    }
    
    for (int i = 0; i <= N; ++i){
        dist[i] = INF;
    }

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(1, 0)); //1번 노드에서 1번 노드의 비용 0
    dist[1] = 0;
    while(!pq.empty()){
        int cur = pq.top().first;
        int curDist = -pq.top().second;
        pq.pop();

        for (int i = 0; i < edge[cur].size(); ++i){ //인접 노드 탐색
            int next = edge[cur][i].first;
            int nextDist = edge[cur][i].second + curDist;

            if (dist[next] > nextDist){ //인접 노드를 지나서 가는것이 더 가까우면 갱신
                dist[next] = nextDist;
                prevNode[next] = cur;   //이전 노드를 갱신
                pq.push(make_pair(next, -nextDist));    
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i <= N; ++i){
        if (prevNode[i] != 0){
            cnt++;
        }
    }
    cout << cnt << endl;

    for (int i = 0; i <= N; ++i){
        if (prevNode[i] != 0){
            cout << prevNode[i] << " " << i << endl;
        }
    }
}