#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define inf 987654321
using namespace std;

priority_queue<vector<int>> pq;

vector<vector<int>> graph[1002];
int dist[1002];
int n,p,k;

void daik(int m){
    fill(dist, dist+1002, inf);
    int next, gap;
    for(int i=0; i<graph[1].size(); i++){
        next = graph[1][i][0];
        gap = graph[1][i][1];
        if(gap > m){
            gap = 1;
        }
        else gap = 0;
        dist[next] = gap;
        pq.push(vector<int>{-gap,next});
    }
    while(!pq.empty()){
        int node = pq.top()[1];
        int d = -pq.top()[0];
        pq.pop();
        for(int i=0; i<graph[node].size(); i++){
            next = graph[node][i][0];
            gap = graph[node][i][1];
            if(gap > m) gap = 1;
            else gap = 0;
            if(dist[next] > d + gap){
                dist[next] = d + gap;
                pq.push(vector<int>{-dist[next],next});
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> k;
    for(int i=0; i<p; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(vector<int>{b,c});
        graph[b].push_back(vector<int>{a,c});
    }
    int L = 0;
    int R = 1000000;
    while(1){
        int M = (L+R)/2;
        daik(M);
        if(dist[n] <= k){
            R = M;
            if(L == R){
                cout << L;
                return 0;
            }
        }
        else L = M+1;
        if(L > R){
            cout << "-1";
            return 0;
        }
    }
}
