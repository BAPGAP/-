#include <iostream>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

vector<pair<int,int>> adj[100001];
int parent[100001];
int deep[100001];
bool visit[100001];
int max_table[17][100001];
int min_table[17][100001];
int table[17][100001];
int INF = 987654321;

void dfs(int x){

    visit[x] = true;
    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i].first;
        if(visit[next]) continue;
        int cost = adj[x][i].second;

        min_table[0][next] = cost;
        max_table[0][next] = cost;

        deep[next] = deep[x] + 1;
        parent[next] = x;
        dfs(next);
    }
}

void LCA(int u,int v){
    int x = u;
    int y = v;
    int lca;

    if(deep[x] > deep[y]) swap(x,y);
    //y가 더 깊이 있음
    int tmp = deep[y] - deep[x];
    for(int i=16; i>=0; i--){
        if(tmp >= (1 << i)){
            tmp -= (1 << i);
            y = table[i][y];
        }
    }
    //이제 깊이 같음

    if(x == y){
        lca = x;
    }
    else{
        for(int i=16; i>=0; i--){
            if(table[i][x] != table[i][y]){
                x = table[i][x];
                y = table[i][y];
            }
        }
        //조상이 다른거 중에 최대를 찾음, 그럼 다음거는 바로 LCA!
        x = table[0][x];
        lca = x;
    }
    int d_u = deep[u] - deep[lca];
    int d_v = deep[v] - deep[lca];
    int mn_u = INF,mx_u = 0;
    int mn_v = INF,mx_v = 0;
    if(d_u != 0){
        for(int i=16; i>=0; i--){
            if(d_u >= (1 << i)){
                mn_u = min(mn_u,min_table[i][u]);
                mx_u = max(mx_u,max_table[i][u]);
                u = table[i][u];
                d_u -= (1 << i);
            }
        }
    }
    if(d_v != 0){
        for(int i=16; i>=0; i--){
            if(d_v >= (1 << i)){
                mn_v = min(mn_v,min_table[i][v]);
                mx_v = max(mx_v,max_table[i][v]);
                v = table[i][v];
                d_v -= (1 << i);
            }
        }
    }
    cout << min(mn_u,mn_v) << " " << max(mx_u,mx_v) << "\n";
}

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    memset(visit,false,sizeof visit);
    parent[1] = 1;
    deep[1] = 0;

    dfs(1); //1을 root 하기로 했어요

    min_table[0][1] = 987654321;
    max_table[0][1] = 0;

    for(int i=1; i<=n; i++){
        table[0][i] = parent[i];
    }

    for(int i=1; i<=16; i++){
        for(int j=1; j<=n; j++){
            min_table[i][j] = min(min_table[i-1][j],min_table[i-1][table[i-1][j]]);
            max_table[i][j] = max(max_table[i-1][j],max_table[i-1][table[i-1][j]]);
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int x,y;
        cin >> x >> y;
        LCA(x,y);
    }
}
