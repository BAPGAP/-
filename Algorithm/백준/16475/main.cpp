#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

priority_queue<vector<int>> pq;
vector<vector<int>> adj[10001];
int dis[10001][11][2]; //0 : 함정발동 안함  //  1 : 함정발동 함
//dis[x][y][z]는 s부터 x까지 최소거리, y는 지금까지 함정 발동된 횟수 , z는 함정발동여부

int INF = INT_MAX;
int trap[10001] = {0};

int main()
{
    int n,m,k,l,p;
    cin >> n >> m >> k >> l >> p;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=p; j++){
            dis[i][j][0] = INF;
            dis[i][j][1] = INF;
        }
    }

    for(int i=0; i<k; i++){
        int x;
        cin >> x;
        trap[x] = 1;
    }
    for(int i=0; i<m-l; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(vector<int>{0,b,c}); //일반길
    }
    for(int i=0; i<l; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(vector<int>{1,b,c}); //처음에는 1
        adj[b].push_back(vector<int>{2,a,c}); //바뀌면 2
    }
    int s,e;
    cin >> s >> e;
    dis[s][0][0] = 0;
    pq.push(vector<int>{0,s,0,0});

    while(!pq.empty()){
        int dist = -pq.top()[0];
        int node = pq.top()[1];
        int total_trap = pq.top()[2];
        int istrap = pq.top()[3];

        pq.pop();

        if(node == e || dis[node][total_trap][istrap] < dist) continue;

        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i][0] == 0 || adj[node][i][0] == istrap + 1){ //길이 있을때
                int next = adj[node][i][1];
                int cost = adj[node][i][2];
                int next_total_trap = total_trap;
                int next_istrap = istrap;

                if(trap[next] == 1){
                    next_total_trap++;
                    if(next_total_trap == p){
                        next_total_trap = 0;
                        next_istrap = 1 - next_istrap;
                    }
                }

                if(dis[next][next_total_trap][next_istrap] > dist + cost){
                    dis[next][next_total_trap][next_istrap] = dist + cost;
                    pq.push(vector<int>{-dis[next][next_total_trap][next_istrap],next,next_total_trap,next_istrap});
                }
            }
        }
    }
    int mn = INF;
    for(int i=0; i<p; i++){
        mn = min(mn,dis[e][i][0]);
        mn = min(mn,dis[e][i][1]);
    }
    if(mn == INF) cout << "-1";
    else cout << mn;
}
