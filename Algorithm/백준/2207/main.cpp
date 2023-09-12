#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[20001];
bool visit[20001] = {0};
int num[20001] = {0};
int cnt = 1;
int scc_cnt = 1;
int scc[20001];
stack<int> s;

int dfs(int x){
    num[x] = cnt++;
    s.push(x);
    int parent = num[x];

    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(num[next] == 0) parent = min(parent,dfs(next));
        else if(!visit[next]) parent = min(parent,num[next]);
    }

    if(parent == num[x]){
        while(1){
            int tmp = s.top();
            s.pop();
            visit[tmp] = true;
            scc[tmp] = scc_cnt;
            if(tmp == x) break;
        }
        scc_cnt++;
    }
    return parent;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int u,v;
        int n_u,n_v;
        cin >> u >> v;
        if(u > 0){
            n_u = 2*u;
            u = 2*u - 1;
        }
        else{
            n_u = 2*(-u)-1;
            u = 2*(-u);
        }
        if(v > 0){
            n_v = 2*v;
            v = 2*v -1;
        }
        else{
            n_v = 2*(-v) - 1;
            v = 2*(-v);
        }
        adj[n_u].push_back(v);
        adj[n_v].push_back(u);
    }

    for(int i=1; i<=2*m; i++){
        if(num[i] == 0) dfs(i);
    }

    bool ok = true;
    for(int i=1; i<=m; i+=2){
        if(scc[i] == scc[i+1]){
            ok = false;
            break;
        }
    }
    if(ok) cout << "^_^";
    else cout << "OTL";
}
