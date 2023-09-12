#include <iostream>
#include <algorithm>

using namespace std;

int parent[1000001];
int Rank[1000001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Merge(int x,int y){
    x = Find(x);
    y = Find(y);

    if(x == y) return;
    if(Rank[x] > Rank[y]) swap(x,y);

    parent[x] = y;
    if(Rank[x] == Rank[y]) Rank[y]++;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int x,y,z;
    for(int i=0; i<=n; i++){
        parent[i] = i;
        Rank[i] = 1;
    }

    for(int i=0; i<m; i++){
        cin >> x >> y >> z;
        if(x == 0){
            Merge(y,z);
        }
        else{
            if(Find(y) == Find(z)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
