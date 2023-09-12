#include <iostream>

using namespace std;

int tri[101][101];
int dp[101][101][2];//0:value  1:cnt

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                cin >> tri[i][j];
            }
        }
        dp[1][1][0] = tri[1][1];
        dp[1][1][1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                if(j==1){
                    dp[i][j][0] = dp[i-1][j][0] + tri[i][j];
                    dp[i][j][1] = dp[i-1][j][1];
                }
                else if(j==i){
                    dp[i][j][0] = dp[i-1][j-1][0] + tri[i][j];
                    dp[i][j][1] = dp[i-1][j-1][1];
                }
                else{
                    if(dp[i-1][j-1][0] > dp[i-1][j][0]){
                        dp[i][j][0] = dp[i-1][j-1][0] + tri[i][j];
                        dp[i][j][1] = dp[i-1][j-1][1];
                    }
                    else if(dp[i-1][j-1][0] < dp[i-1][j][0]){
                        dp[i][j][0] = dp[i-1][j][0] + tri[i][j];
                        dp[i][j][1] = dp[i-1][j][1];
                    }
                    else{
                        dp[i][j][0] = dp[i-1][j][0] + tri[i][j];
                        dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j-1][1];
                    }
                }
            }
        }

        int mx = -1;
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(mx < dp[n][i][0]){
                mx = dp[n][i][0];
                cnt = dp[n][i][1];
            }
            else if(mx == dp[n][i][0]){
                cnt += dp[n][i][1];
            }
        }
        cout << cnt << "\n";
    }
}
