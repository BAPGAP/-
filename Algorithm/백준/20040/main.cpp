#include <iostream>
#include <algorithm>

using namespace std;

int parent[500001];
int h[500001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Merge(int x,int y){
    x = Find(x);
    y = Find(y);

    if(x == y) return;

    if(h[x] > h[y]) swap(x,y);

    parent[x] = y;

    if(h[x] == h[y]) h[y]++;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        parent[i] = i;
        h[i] = 1;
    }

    int x,y,Answer = 0;
    for(int i=1; i<=m; i++){
        cin >> x >> y;
        if(Answer != 0) continue;

        if(Find(x) == Find(y)) Answer = i;
        else Merge(x,y);
    }
    cout << Answer;
}
