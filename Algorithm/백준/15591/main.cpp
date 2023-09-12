#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int inf = 987654321;
int dist[5001][5001];
int n,q;
vector<vector<int>> tree[5001];
int visit[5001] = {0};
int start;
void print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << dist[i][j] << "  ";
        }
        cout << "\n";
    }
}
void dfs(int node, int mn){
    visit[node] = 1;
    int next,val;
    for(int i=0; i<tree[node].size(); i++){
        next = tree[node][i][0];
        val = tree[node][i][1];
        if(visit[next] == 0){
            dist[start][next] = min(mn,val);
            dist[next][start] = dist[start][next];
            dfs(next, dist[start][next]);
        }
    }
    visit[node] = 0;
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    fill(dist[0],dist[5001],inf);
    cin >> n >> q;
    for(int i=1; i<n; i++){
        int x,y,z;
        cin >> x >> y >> z;
        tree[x].push_back(vector<int>{y,z});
        tree[y].push_back(vector<int>{x,z});
        dist[x][y] = z;
        dist[y][x] = z;
    }
    //print();
    for(int i=1; i<=n; i++){
        start = i;
        dfs(i,inf);
    }
    //print();
    for(int i=0; i<q; i++){
        int k,v;
        cin >> k >> v;
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(j==v) continue;
            if(dist[v][j] >= k) cnt++;
        }
        cout << cnt << "\n";
    }
}
