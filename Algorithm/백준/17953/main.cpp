#include <iostream>

using namespace std;
int n,m;

int a[11][100001];
int dp[11][100001];

int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
        dp[i][1] = a[i][1];
    }
    for(int j=2; j<=n; j++){
        for(int k=1; k<=m; k++){
            int mx = 0;
            for(int i=1; i<=m; i++){
                if(i != k) mx = max(mx,dp[i][j-1]);
            }
            dp[k][j] = max(mx+a[k][j],dp[k][j-1]+a[k][j]/2);
        }
    }
    int mmax = 0;
    for(int i=1; i<=m; i++){
        mmax = max(mmax,dp[i][n]);
    }

    /*
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << mmax;
}
