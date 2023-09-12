#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int e[100001];
vector<pair<int,int>> adj[100001];
int deep[100001];
int table[17][100001];
bool visit[100001];
int cost[100001];

void dfs(int x){
    visit[x] = true;
    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i].first;
        if(visit[next]) continue;
        int w = adj[x][i].second;
        deep[next] = deep[x] + 1;
        table[0][next] = x;
        cost[next] = cost[x] + w;
        dfs(next);
    }
}

void LCA(int x){
    if(cost[x] <= e[x]){
        cout << "1\n";
    }
    else{
        int diff = e[x];
        for(int i=16; i>=0; i--){
            if(diff >= cost[x] - cost[table[i][x]]){
                diff -= cost[x] - cost[table[i][x]];
                x = table[i][x];
            }
        }
        cout << x << "\n";
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> e[i];
    }
    memset(visit,false,sizeof visit);
    for(int i=1; i<n; i++){
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    cost[1] = 0;
    deep[1] = 0;
    table[0][1] = 1;
    dfs(1);
    for(int i=1; i<=16; i++){
        for(int j=1; j<=n; j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
    for(int i=1; i<=n; i++){
        LCA(i);
    }
}
