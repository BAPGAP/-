#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost[10001];
vector<int> adj[10001];
vector<int> dp[10001][2]; //0:not choose, 1: choose, dp[x][0 or 1][0] : sum, dp[x][0 or 1][나머지] : 경로
bool visit[10001];

void dfs(int x){
    visit[x] = true;
    dp[x][1][0] += cost[x];
    dp[x][1].push_back(x);

    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(visit[next]) continue;

        dfs(next);

        int no = dp[next][0][0];
        int yes = dp[next][1][0];
        if(no < yes){ //자식 골랐을때 더 큼
            dp[x][0][0] += yes;
            dp[x][1][0] += no;
            for(int j=1; j<dp[next][1].size(); j++){
                dp[x][0].push_back(dp[next][1][j]);
            }
            for(int j=1; j<dp[next][0].size(); j++){
                dp[x][1].push_back(dp[next][0][j]);
            }
        }
        else{
            dp[x][1][0] += no;
            dp[x][0][0] += no;
            for(int j=1; j<dp[next][0].size(); j++){
                dp[x][1].push_back(dp[next][0][j]);
                dp[x][0].push_back(dp[next][0][j]);
            }
        }
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
        dp[i][0].push_back(0);
        dp[i][1].push_back(0);
        visit[i] = false;
    }
    int x,y;
    for(int i=1; i<n; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    if(dp[1][1][0] > dp[1][0][0]){
        cout << dp[1][1][0] << "\n";
        sort(dp[1][1].begin()+1,dp[1][1].end());
        for(int i=1; i<dp[1][1].size(); i++){
            cout << dp[1][1][i] << " ";
        }
    }
    else{
        cout << dp[1][0][0] << "\n";
        sort(dp[1][0].begin()+1,dp[1][0].end());
        for(int i=1; i<dp[1][0].size(); i++){
            cout << dp[1][0][i] << " ";
        }
    }
}
