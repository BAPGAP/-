#include <iostream>

using namespace std;

int a[1001][1001];

int main()
{
    int n,k;
    int m;
    cin >> m;
    a[1][0] = 1;
    a[1][1] = 1;
    a[2][0] = 1;
    a[2][1] = 2;
    a[2][2] = 1;
    for(int i=3; i<=30; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i) a[i][j] = 1;
            else a[i][j] = (a[i-1][j-1] + a[i-1][j]);
        }
    }
    for(int i=0; i<m; i++){
        cin >> n >> k;
        cout << a[k][n] << endl;
    }
}
