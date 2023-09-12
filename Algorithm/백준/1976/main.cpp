#include <iostream>
#include <algorithm>

using namespace std;

int Parent[201];
int Rank[201];
int M[1001];

int Find(int x){
    if(x == Parent[x]) return x;
    return Parent[x] = Find(Parent[x]);
}

void Merge(int x,int y){
    x = Find(x);
    y = Find(y);

    if(x == y) return;

    if(Rank[x] > Rank[y]) swap(x,y);

    Parent[x] = y;

    if(Rank[x] == Rank[y]) Rank[y]++;
}


int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        Parent[i] = i;
        Rank[i] = 1;
    }
    int x;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> x;
            if(x == 1) Merge(i,j);
        }
    }

    for(int i=1; i<=m; i++){
        cin >> M[i];
    }
    bool isok = true;
    for(int i=2; i<=m; i++){
        if(Find(M[i-1]) != Find(M[i])){
            isok = false;
            break;
        }
    }
    if(isok) cout << "YES\n";
    else cout << "NO\n";
}
