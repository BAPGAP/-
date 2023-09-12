#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

vector<int> adj[4001];
bool visit[4001];
int num[4001];
int cnt;
int scc_cnt;
stack<int> s;
int scc[4001];

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
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n,m,k;
        cin >> n >> m >> k;
        for(int i=0; i<k; i++){
            int a,b,c,d;
            int n_a,n_b,n_c,n_d;
            cin >> a >> b >> c >> d;
            if(a == c && b == d) continue;

            if(a == c){
                if(b < d) adj[2*a].push_back(2*a-1);
                else adj[2*a-1].push_back(2*a);
                continue;
            }
            if(b == d){
                if(a < c) adj[2*(b+n)].push_back(2*(b+n)-1);
                else adj[2*(b+n)-1].push_back(2*(b+n));
                continue;
            }
            if(a < c){
                n_b = 2*(b+n);
                b = 2*(b+n) - 1;
                n_d = 2*(d+n);
                d = 2*(d+n) - 1;
            }
            else{
                n_b = 2*(b+n) - 1;
                b = 2*(b+n);
                n_d = 2*(d+n) - 1;
                d = 2*(d+n);
            }
            if(b < d){
                n_a = 2*a;
                a = 2*a - 1;
                n_c = 2*c;
                c = 2*c - 1;
            }
            else{
                n_a = 2*a - 1;
                a = 2*a;
                n_c = 2*c - 1;
                c = 2*c;
            }
            adj[n_a].push_back(b);
            adj[n_a].push_back(c);
            adj[n_b].push_back(a);
            adj[n_b].push_back(d);
            adj[n_c].push_back(a);
            adj[n_c].push_back(d);
            adj[n_d].push_back(b);
            adj[n_d].push_back(c);
        }
        memset(visit,false,sizeof visit);
        memset(num,0,sizeof num);
        cnt = 1;
        scc_cnt = 1;
        for(int i=1; i<=2*(n+m); i++){
            if(num[i] == 0) dfs(i);
        }
        bool ok = true;
        for(int i=1; i<=2*(n+m); i+=2){
            if(scc[i] == scc[i+1]){
                ok = false;
                break;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
        for(int i=1; i<=2*(n+m); i++){
            vector<int>().swap(adj[i]);
        }
    }
}
