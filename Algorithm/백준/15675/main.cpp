#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[4001];
int cnt = 1;
int scc_cnt = 1;
int num[4001] = {0};
bool visit[4001] = {0};
int scc[4001];
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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    char c;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> c;
            if(c == '*'){
                adj[2*i-1].push_back(2*(n+j));
                adj[2*(n+j)-1].push_back(2*i);
                adj[2*(n+j)].push_back(2*i-1);
                adj[2*i].push_back(2*(n+j)-1);
            }
            else if(c == '#'){
                adj[2*i-1].push_back(2*(n+j)-1);
                adj[2*(n+j)-1].push_back(2*i-1);
            }
        }
    }
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
    if(ok) cout << "1";
    else cout << "0";
}

