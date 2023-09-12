#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int a[10001];
int deep[10001];
vector<int> adj[10001];

void dfs(int x){
    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        deep[next] = deep[x] + 1;
        dfs(next);
    }
}

int LCA(int x,int y){
    if(deep[x] > deep[y]) swap(x,y);
    while(deep[x] != deep[y]){
        y = a[y];
    }
    //이제 깊이 같음
    while(x != y){
        x = a[x];
        y = a[y];
    }
    return x;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            a[i] = i;
        }
        for(int i=1; i<n; i++){
            int u,v;
            cin >> u >> v;
            a[v] = u; //u가 v의 parent // u -> v
            adj[u].push_back(v);
        }
        int root = a[1];
        while(root != a[root]){
            root = a[root];
        }
        deep[root] = 0;
        dfs(root);

        int x,y;
        cin >> x >> y;
        cout << LCA(x,y) << "\n";

        for(int i=1; i<=n; i++){
            vector<int>().swap(adj[i]);
        }
    }
}
