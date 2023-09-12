#include <iostream>

using namespace std;

int cost[1001][3];
int dp[10][1001];
int INF = 987654321;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> cost[i][j];
        }
    }
    int cnt = 1;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == j) dp[cnt][1] = INF;
            else dp[cnt][1] = cost[0][i] + cost[1][j];
            cnt++;
        }
    }

    for(int i=2; i<n; i++){
        dp[1][i] = min(dp[2][i-1],dp[3][i-1]) + cost[i][0];
        dp[2][i] = min(dp[1][i-1],dp[3][i-1]) + cost[i][1];
        dp[3][i] = min(dp[1][i-1],dp[2][i-1]) + cost[i][2];
        dp[4][i] = min(dp[5][i-1],dp[6][i-1]) + cost[i][0];
        dp[5][i] = min(dp[4][i-1],dp[6][i-1]) + cost[i][1];
        dp[6][i] = min(dp[4][i-1],dp[5][i-1]) + cost[i][2];
        dp[7][i] = min(dp[8][i-1],dp[9][i-1]) + cost[i][0];
        dp[8][i] = min(dp[7][i-1],dp[9][i-1]) + cost[i][1];
        dp[9][i] = min(dp[7][i-1],dp[8][i-1]) + cost[i][2];
    }
    int R = min(dp[2][n-1],dp[3][n-1]);
    int G = min(dp[4][n-1],dp[6][n-1]);
    int B = min(dp[7][n-1],dp[8][n-1]);

    cout << min(min(R,G),B);
}
