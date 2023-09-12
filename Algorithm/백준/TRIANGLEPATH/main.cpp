#include <iostream>

using namespace std;

int a[101][101] = {0};
int b[101][101] = {0};

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                cin >> a[i][j];
                if(i==1 && j==1) b[i][j] = a[i][j];
                else if(j==1) b[i][j] = b[i-1][j] + a[i][j];
                else if(j==i) b[i][j] = b[i-1][j-1] + a[i][j];
                else b[i][j] = max(b[i-1][j],b[i-1][j-1]) + a[i][j];
            }
        }
        int mx = b[n][1];
        for(int i=2; i<=n; i++){
            mx = max(mx,b[n][i]);
        }
        cout << mx << "\n";
    }
}
