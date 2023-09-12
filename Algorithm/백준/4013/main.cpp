#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

vector<int> adj[500001];
int w[500001];
bool resto[500001]; //resto[i] = true면 i에 레스토랑 있음
int scc[500001]; //어느 scc에 속하나요?
int num[500001] = {0}; //num[i] = 0이면 아직 방문안함
bool visit[500001];
int cnt = 1;
int scc_cnt = 1;
stack<int> s;

vector<int> scc_sum; //각 scc 총합
vector<bool> scc_res; //레스토랑 여부
vector<int> scc_adj[500001];
int dp[500001] = {0};
int Answer = 0;

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
        int sum = 0;
        bool has_res = false;
        while(1){
            int tmp = s.top();
            s.pop();
            sum += w[tmp];
            scc[tmp] = scc_cnt;
            visit[tmp] = true;
            if(resto[tmp]) has_res = true;
            if(tmp == x) break;
        }
        scc_sum.push_back(sum);
        scc_res.push_back(has_res);
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
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }
    int s,p;
    cin >> s >> p;
    memset(resto,false,sizeof resto);
    memset(visit,false,sizeof visit);
    for(int i=0; i<p; i++){
        int x;
        cin >> x;
        resto[x] = true;
    }
    scc_sum.push_back(0);
    scc_res.push_back(false);
    for(int i=1; i<=n; i++){
        if(num[i] == 0) dfs(i);
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            int next = adj[i][j];
            if(scc[i] != scc[next]){
                scc_adj[scc[i]].push_back(scc[next]);
            }
        }
    }
    //s가 출발지점
    dp[scc[s]] = scc_sum[scc[s]];
    for(int i=scc[s]; i>0; i--){
        if(scc_res[i] && Answer < dp[i]) Answer = dp[i];
        for(int j=0; j<scc_adj[i].size(); j++){
            int next = scc_adj[i][j];
            dp[next] = max(dp[next],dp[i] + scc_sum[next]);
        }
    }
    cout << Answer;
}
