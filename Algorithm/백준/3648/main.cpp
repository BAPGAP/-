#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

vector<int> adj[2001];
int num[2001];
bool visit[2001];
int cnt;
int scc_cnt;
stack<int> s;
int scc[2001];

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
    while(cin >> n >> m){
        for(int i=0; i<m; i++){
            int u,v;
            int not_u,not_v;
            cin >> u >> v; //u U v = ~u -> v, ~v -> u
            if(u > 0){
                not_u = 2*u;
                u = 2*u-1;
            }
            else{
                not_u = 2*(-u)-1;
                u = 2*(-u);
            }
            if(v > 0){
                not_v = 2*v;
                v = 2*v-1;
            }
            else{
                not_v = 2*(-v)-1;
                v = 2*(-v);
            }
            if(v == not_u) continue;
            adj[not_u].push_back(v);
            adj[not_v].push_back(u);
        }
        bool two = true;
        for(int i=0; i<adj[2].size(); i++){
            if(adj[2][i] == 1){
                two = false;
                break;
            }
        }
        if(two) adj[2].push_back(1);

        memset(visit,false,sizeof visit);
        memset(num,0,sizeof num);

        cnt = 1;
        scc_cnt = 1;
        for(int i=1; i<=2*n; i++){
            if(num[i] == 0) dfs(i);
        }
        bool ok = true;
        for(int i=1; i<=n; i+=2){
            if(scc[i] == scc[i+1]){
                ok = false;
                break;
            }
        }
        if(ok) cout << "yes\n";
        else cout << "no\n";
        for(int i=1; i<=2*n; i++){
            vector<int>().swap(adj[i]);
        }
    }
}
