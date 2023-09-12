#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

vector<pair<int,long long>> adj[100001];

int degree[100001] = {0};

bool visit[100001];

void dfs(int x,long long gap){
    visit[x] = true;
    bool isleaf = true;
    for(int i=0; i<(int)adj[x].size(); i++){
        int next = adj[x][i].first;
        long long cost = adj[x][i].second;
        if(!visit[next]){
            isleaf = false;
            dfs(next,gap+cost);
        }
    }
    if(isleaf){
        if(mx < gap) mx = gap;
        if(mn > gap) mn = gap;
    }
}

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        degree[a]++;
        degree[b]++;
    }
    for(int i=0; i<n; i++){
        if(degree[i] == 1){
            memset(visit,false,sizeof(visit));
            dfs(i,0);
        }
    }
    cout << mx << "\n" << mn;
}
