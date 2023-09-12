#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int num[40001];
bool visit[40001];
int cnt;
int scc_cnt;
vector<int> adj[40001];
int scc[40001];

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

int no(int x){
    if(x%2 == 1) return x+1;
    else return x-1;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;

        memset(num,0,sizeof num);
        memset(visit,false,sizeof visit);
        cnt = 1;
        scc_cnt = 1;

        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            if(x < 0) x = (-x) * 2;
            else x = 2*x-1;
            if(y < 0) y = (-y) * 2;
            else y = 2*y-1;
            adj[x].push_back(no(y));
            adj[y].push_back(no(x));
        }

        for(int i=1; i<=2*m; i++){
            if(num[i] == 0) dfs(i);
        }
        bool ok = true;
        for(int i=1; i<=2*m; i+=2){
            if(scc[i] == scc[i+1]){
                ok = false;
                break;
            }
        }
        if(ok) cout << "1\n";
        else cout << "0\n";

        for(int i=1; i<=2*m; i++){
            vector<int>().swap(adj[i]);
        }
    }
}
