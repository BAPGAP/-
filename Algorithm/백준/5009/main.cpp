#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int n;
int ban[401][4];
int F[401][401];
int num[401];
bool visit[401];
int cnt;
int scc_cnt;
stack<int> s;
int scc[401];
vector<int> adj[401];

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

bool solve(int m){ //상위 m위 까지
    cnt = 1;
    scc_cnt = 1;
    memset(visit,false,sizeof visit);
    memset(num,0,sizeof num);

    for(int i=1; i<=n; i++){
        for(int j=m+1; j<n; j++){
            int fri = F[i][j];
            for(int k=0; k<3; k++){
                if(ban[i][k] > 0 && ban[fri][k]){
                    int u = ban[i][k];
                    int v = ban[fri][k];
                    adj[u].push_back(no(v));
                    adj[v].push_back(no(u));
                }
            }
        }
    }

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
    for(int i=1; i<=2*n; i++){
        vector<int>().swap(adj[i]);
    }
    return ok;
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        int node = 2*i-1;
        for(int j=0; j<3; j++){
            if(j == x){
                ban[i][j] = 0;
            }
            else{
                ban[i][j] = node;
                node++;
            }
        }
        for(int j=1; j<=n-1; j++){
            cin >> F[i][j];
        }
    }
    int L = 0;
    int R = n-1;
    int Answer = n-1;
    while(L <= R){
        int M = (L+R)/2;

        if(solve(M)){
            Answer = M;
            R = M-1;
        }
        else L = M+1;
    }
    cout << Answer;
}
