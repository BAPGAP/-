#include <iostream>

using namespace std;

int dp[101][101] = {0};
int L[101][101] = {0};

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        L[a][b] = 1;
        L[b][a] = 1;
    }

    for(int i=1; i<=100; i++){
        for(int j=i; j>0; j--){
            for(int k=j; k<i; k++){
                dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] + L[i][j]);
                dp[j][i] = max(dp[j][i],dp[j][k] + dp[k][i] + L[j][i]);
            }
        }
    }
    cout << dp[1][100];
}
