#include <iostream>

using namespace std;

int parent[1001];
int height[1001];
int sum;

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Merge(int x,int y){
    int x_p = Find(x);
    int y_p = Find(y);

    if(x_p == y_p) return;

    sum++;
    if(height[x_p] > height[y_p]) swap(x_p,y_p);

    parent[x_p] = y_p;

    if(height[x_p] == height[y_p]) height[y_p]++;
}


int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n,m;
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            parent[i] = i;
            height[i] = 1;
        }
        sum = 0;
        for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;
            Merge(x,y);
        }
        cout << sum << "\n";
    }
}
