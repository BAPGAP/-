#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[200001];
int cnt;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        if(x > y) swap(x,y);
        adj[x].push_back(y);
    }
    cnt = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].size() == 0) cnt++;
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int x;
        cin >> x;
        if(x == 1){
            int u,v;
            cin >> u >> v;
            if(u > v) swap(u,v);
            adj[u].push_back(v);
            if(adj[u].size() == 1) cnt--;
        }
        else if(x == 2){
            int u,v;
            cin >> u >> v;
            if(u > v) swap(u,v);
            for(int i=0; i<adj[u].size(); i++){
                if(adj[u][i] == v){
                    adj[u].erase(adj[u].begin() + i);
                    break;
                }
            }
            if(adj[u].size() == 0) cnt++;
        }
        else{
            cout << cnt << "\n";
        }
    }
}
