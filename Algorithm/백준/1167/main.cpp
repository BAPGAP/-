#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int,int>> v[100001];
int dis[100001] = {0};
int visit[100001] = {0};
int long_node;

void dfs(int x){
    visit[x] = 1;
    for(int i=0; i<v[x].size(); i++){
        int next = v[x][i].first;
        if(visit[next] == 1) continue;
        int cost = v[x][i].second;
        dis[next] = dis[x] + cost; //트리에서는 각 점들끼리 경로가 유일하다
        if(dis[next] > dis[long_node]) long_node = next;
        dfs(next);
    }
    return;
}

void dfs_(int x){
    visit[x] = 0;
    for(int i=0; i<v[x].size(); i++){
        int next = v[x][i].first;
        if(visit[next] == 0) continue;
        int cost = v[x][i].second;
        dis[next] = dis[x] + cost; //트리에서는 각 점들끼리 경로가 유일하다
        if(dis[next] > dis[long_node]) long_node = next;
        dfs_(next);
    }
    return;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int node;
        cin >> node;
        int x,y;
        while(1){
            cin >> x;
            if(x == -1) break;
            cin >> y;
            v[node].push_back(make_pair(x,y));
        }
    }
    long_node = 1;
    dis[1] = 0;
    dfs(1);
    dis[long_node] = 0;
    dfs_(long_node);
    cout << dis[long_node] << "\n";
}
