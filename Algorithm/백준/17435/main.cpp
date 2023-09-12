#include <iostream>
#include <cmath>

using namespace std;

int a[200001];
int INF = 500000;
int table[19][200001];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> a[i];
    }
    for(int i=1; i<=m; i++){
        table[0][i] = a[i];
    }
    for(int i=1; i<19; i++){
        for(int j=1; j<=m; j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }

    int q;
    cin >> q;
    int n,x;
    for(int i=0; i<q; i++){
        cin >> n >> x;
        int tmp = x;
        for(int j=18; j>=0; j--){
            if(n >= (1 << j)){
                tmp = table[j][tmp];
                n -= (1 << j);
            }
        }
        cout << tmp << "\n";
    }
}
