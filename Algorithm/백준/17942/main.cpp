#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int a[100001];
bool check[100001];
int n,m;
vector<pair<int,int>> v[100001];
priority_queue<pair<int,int>> q;

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        check[i] = false;
        q.push(make_pair(-a[i],i));
    }
    int r;
    cin >> r;
    int x,y,z;
    for(int i=0; i<r; i++){
        cin >> x >> y >> z;
        v[x].push_back(make_pair(y,z));
    }
    int Answer = -1;
    int cnt = 0;
    while(cnt != m){
        int study = -q.top().first;
        int node = q.top().second;
        q.pop();
        if(check[node]) continue;

        Answer = max(Answer,a[node]);
        check[node] = true;
        cnt++;

        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i].first;
            int cost = v[node][i].second;
            a[next] -= cost;
            q.push(make_pair(-a[next],next));
        }
    }
    cout << Answer;
}
