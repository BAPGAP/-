#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
int comp[1001];
vector<vector<int>> adj[1001];
bool check[1001];

struct cmp{
    bool operator()(vector<int> x,vector<int> y){
        if(x[0] == y[0]) return x[1] > y[1];
        else return x[0] > y[0];
    }
};

priority_queue<vector<int>,vector<vector<int>>,cmp> q;

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> comp[i];
        check[i] = false;
    }
    int x;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> x;
            if(x > 0){
                adj[i].push_back(vector<int>{j,x});
                adj[j].push_back(vector<int>{i,x});
            }
        }
    }
    q.push(vector<int>{0,0,0});
    while(1){
        int hwan = q.top()[0];
        int dis = q.top()[1];
        int node = q.top()[2];
        q.pop();
        if(check[node]) continue;

        if(node == m){
            cout << hwan << " " << dis;
            return 0;
        }
        for(int i=0; i<adj[node].size(); i++){
            int next = adj[node][i][0];
            int cost = adj[node][i][1];

            if(check[next]) continue;

            if(comp[node] == comp[next]){
                q.push(vector<int>{hwan,dis+cost,next});
            }
            else{
                q.push(vector<int>{hwan+1,dis+cost,next});
            }
        }
        check[node] = true;
    }
}
