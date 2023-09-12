#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

vector<int> adj[2001];
stack<int> s;
int cnt;
int scc_cnt;
int num[2001];
bool visit[2001];
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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    while(cin >> n >> m){
        for(int i=0; i<m; i++){
            char a,b;
            int x,y;
            int n_x,n_y;
            cin >> a >> x >> b >> y;
            if(x == y && a != b){
                continue;
            }

            if(a == '+'){
                n_x = 2*x;
                x = 2*x - 1;
            }
            else{
                n_x = 2*x-1;
                x = 2*x;
            }
            if(b == '+'){
                n_y = 2*y;
                y = 2*y - 1;
            }
            else{
                n_y = 2*y-1;
                y = 2*y;
            }

            if(x == y){
                adj[n_x].push_back(y);
                continue;
            }
            adj[n_x].push_back(y);
            adj[n_y].push_back(x);
        }

        memset(visit,false,sizeof visit);
        memset(num,0,sizeof num);
        cnt = 1;
        scc_cnt = 1;

        for(int i=1; i<=2*n; i++){
            if(num[i] == 0) dfs(i);
        }

        bool ok = true;
        for(int i=1; i<=2*n; i+=2){
            if(scc[i] == scc[i+1]){
                ok = false;
                break;
            }
        }
        if(ok) cout << "1\n";
        else cout << "0\n";
        for(int i=1; i<=2*n; i++){
            vector<int>().swap(adj[i]);
        }
    }
}
