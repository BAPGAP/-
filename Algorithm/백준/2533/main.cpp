#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> adj[1000001];
int dp[1000001][2]; //0 : ���̾����, 1 : �Ϲ���
bool visit[1000001];

void dfs(int x){
    visit[x] = true;
    dp[x][0] = 1;
    dp[x][1] = 0;

    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i]; //�ڽ�
        if(visit[next]) continue; //�ڽľƴ�
        dfs(next);
        dp[x][0] += min(dp[next][0],dp[next][1]);
        dp[x][1] += dp[next][0];
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int x,y;
    for(int i=1; i<n; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        visit[i] = false;
    }
    visit[n] = false;
    dfs(1); //���Ƿ� 1�� root�� �ؼ� Ž�� ����
    cout << min(dp[1][0],dp[1][1]);
}
