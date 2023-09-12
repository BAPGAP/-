#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[32001];
int in[32001] = {0};


struct cmp{
    bool operator()(pair<int,int> x,pair<int,int> y){
        if(x.first == y.first) return x.second > y.second;
        return x.first > y.first;
    } //높이라고 생각하면됨
};

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
        in[v]++;
    }
    vector<int> pre;
    for(int i=1; i<=n; i++){
        if(in[i] == 0) pre.push_back(i);
    }
    sort(pre.begin(),pre.end());

    for(int i=1; i<pre.size(); i++){
        int node = pre[i-1];
        int next = pre[i];
        adj[node].push_back(next);
        in[next]++;
    }
    int root = pre[0];

    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;

    q.push({0,root}); //들어오는 간선, 헤당노드

    while(!q.empty()){
        int in_cnt = q.top().first;
        int node = q.top().second;
        q.pop();
        if(in_cnt != 0) continue;

        cout << node << " ";

        for(int i=0; i<adj[node].size(); i++){
            int next = adj[node][i];
            if(in[next] == 0) continue;
            in[next]--;
            q.push({in[next],next});
        }
    }
}
