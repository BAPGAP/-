#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

typedef long long ll;

vector<pair<int,ll>> adj[100001];
long long cost[100001]; //root 부터 내리갈굼
int deep[100001];
bool visit[100001];
int table[17][100001];

void dfs(int x){
    visit[x] = true;
    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i].first;
        if(visit[next]) continue;
        ll w = adj[x][i].second;

        table[0][next] = x;
        cost[next] = cost[x] + w;
        deep[next] = deep[x] + 1;
        dfs(next);
    }
}

void type1(int u,int v){
    int x = u;
    int y = v;
    if(deep[x] > deep[y]) swap(x,y);
    int diff = deep[y] - deep[x];
    for(int i=16; i>=0; i--){
        if(diff >= (1 << i)){
            y = table[i][y];
            diff -= (1 << i);
        }
    }
    //이제 높이 같아짐
    int lca;

    if(x == y) lca = x;

    else{
        for(int i=16; i>=0; i--){
            if(table[i][x] != table[i][y]){
                x = table[i][x];
                y = table[i][y];
            }
        }
        //안맞을때마다 조상을 찾으러 갔으므로 딱 맞기 일보직전이다.
        lca = table[0][x]; //최소 공통 조상 찾음
    }

    ll Answer = cost[u] + cost[v] - 2 * cost[lca];
    cout << Answer << "\n";
}

void type2(int u,int v,int k){
    int x = u;
    int y = v;
    if(deep[x] > deep[y]) swap(x,y);
    int diff = deep[y] - deep[x];
    for(int i=16; i>=0; i--){
        if(diff >= (1 << i)){
            y = table[i][y];
            diff -= (1 << i);
        }
    }
    //이제 높이 같아짐

    int lca;

    if(x == y) lca = x;
    else{
        for(int i=16; i>=0; i--){
            if(table[i][x] != table[i][y]){
                x = table[i][x];
                y = table[i][y];
            }
        }
        //안맞을때마다 조상을 찾으러 갔으므로 딱 맞기 일보직전이다.
        lca = table[0][x]; //최소 공통 조상 찾음
    }

    if(deep[u] - deep[lca] + 1 >= k){
        int tmp = k-1;
        if(tmp == 0) cout << u << "\n";
        else{
            for(int i=16; i>=0; i--){
                if(tmp >= (1 << i)){
                    u = table[i][u];
                    tmp -= (1 << i);
                }
            }
            cout << u << "\n";
        }
    }
    else{
        int tmp = deep[u] + deep[v] - 2 * deep[lca] + 1 - k;
        if(tmp == 0) cout << v << "\n";
        else{
            for(int i=16; i>=0; i--){
                if(tmp >= (1 << i)){
                    v = table[i][v];
                    tmp -= (1 << i);
                }
            }
            cout << v << "\n";
        }
    }
}

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int u,v;
        ll c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    memset(visit,false,sizeof visit);
    cost[1] = 0;
    table[0][1] = 1;
    deep[1] = 0;
    dfs(1);

    for(int i=1; i<=16; i++){
        for(int j=1; j<=n; j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int x;
        cin >> x;
        if(x == 1){
            int u,v;
            cin >> u >> v;
            type1(u,v);
        }
        else{
            int u,v,k;
            cin >> u >> v >> k;
            type2(u,v,k);
        }
    }
}
