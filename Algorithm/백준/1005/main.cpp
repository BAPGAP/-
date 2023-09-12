#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[1001];
int indegree[1001];
int cost[1001];
int dis[1001];

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int n,k;
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            cin >> cost[i];
            indegree[i] = 0;
            dis[i] = 0;
        }
        int x,y;
        for(int i=0; i<k; i++){
            cin >> x >> y;
            v[x].push_back(y);
            indegree[y]++;
        }

        queue<int> q;
        for(int i=1; i<=n; i++){
            if(indegree[i] == 0){
                if(v[i].size() > 0) q.push(i);
                dis[i] = cost[i];
            }
        }

        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            if(indegree[tmp] > 0){
                q.push(tmp);
                continue;
            }
            for(int i=0; i<v[tmp].size(); i++){
                int next = v[tmp][i];
                indegree[next]--;
                dis[next] = max(dis[next],dis[tmp] + cost[next]);
                q.push(next);
            }
            vector<int>().swap(v[tmp]);
        }

        int W;
        cin >> W;
        cout << dis[W] << "\n";
    }
}
