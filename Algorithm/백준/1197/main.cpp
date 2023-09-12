#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int parent[10001];
int height[10001];

int sum = 0;

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Merge(int a,int b,int c){
    int x = Find(a);
    int y = Find(b);

    if(x == y) return;

    sum += c;

    if(height[x] > height[y]) swap(x,y);

    parent[x] = y;

    if(height[x] == height[y]) height[y]++;
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int v,e;
    cin >> v >> e;
    for(int i=1; i<=v; i++){
        parent[i] = i;
        height[i] = 1;
    }
    priority_queue<vector<int>> q;
    for(int i=0; i<e; i++){
        int x,y,z;
        cin >> x >> y >> z;
        q.push(vector<int>{-z,x,y});
    }
    while(!q.empty()){
        int node1 = q.top()[1];
        int node2 = q.top()[2];
        int cost = -q.top()[0];
        q.pop();
        Merge(node1,node2,cost);
    }
    cout << sum;
}
