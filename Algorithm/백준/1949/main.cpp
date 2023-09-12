#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost[10001];
vector<int> adj[10001];
int dp[10001][2]; //0:not choose, 1: choose
bool visit[10001];

void dfs(int x){
    visit[x] = true;
    dp[x][1] += cost[x];

    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(visit[next]) continue;
        dfs(next);
        dp[x][1] += dp[next][0];
        dp[x][0] += max(dp[next][0],dp[next][1]);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> cost[i];
        dp[i][0] = 0;
        dp[i][1] = 0;
        visit[i] = false;
    }
    int x,y;
    for(int i=1; i<n; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    cout << max(dp[1][1],dp[1][0]);
}
