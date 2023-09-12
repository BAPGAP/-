#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[100001];
int degree[100001] = {0};
queue<pair<int,int>> pq;

int main()
{

    //cin.tie(NULL);
    //ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt_all = n;
    int cnt_one = 0;
    int cnt_two = 0;
    for(int i=0; i<n; i++){
        degree[i] = (int)adj[i].size();
        if(degree[i] == 1){
            pq.push({-degree[i],i});
            cnt_one++;
        }
        else if(degree[i] == 2) cnt_two++;
    }
    while(1){
        int d = -pq.front().first;
        int node = pq.front().second;
        pq.pop();
        if(degree[node] != d) continue;

        if(cnt_one == 2 && cnt_all == cnt_one + cnt_two) break;


        for(int i=0; i<(int)adj[node].size(); i++){
            int next = adj[node][i];
            if(degree[next]>1){
                if(degree[next]==2){
                    cnt_two--;
                    cnt_one++;
                }
                else if(degree[next]==3){
                    cnt_two++;
                }
                degree[next]--;
                pq.push({-degree[next],next});
            }
            else degree[next]--;
        }
        degree[node]--;
        cnt_one--;
        cnt_all--;
    }
    for(int i=0; i<n; i++){
        if(degree[i] > 0){
            cout << i << " ";
        }
    }
}
