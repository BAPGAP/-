#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> adj[32001];
int in[32001] = {0};

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    priority_queue<pair<int,int>> q;
    for(int i=1; i<=n; i++){
        q.push({-in[i],i});
    }
    while(!q.empty()){
        int node = q.top().second;
        int dim = -q.top().first;
        q.pop();
        if(dim != 0) continue;
        cout << node << " ";
        for(int i=0; i<adj[node].size(); i++){
            int next = adj[node][i];
            in[next]--;
            q.push({-in[next],next});
        }
    }
}
