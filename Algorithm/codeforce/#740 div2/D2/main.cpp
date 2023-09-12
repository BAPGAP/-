#include <iostream>

using namespace std;

long long dp[4000001] = {0};

int main()
{
    long long n,m;
    cin >> n >> m;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    dp[4] = 12;
    dp[5] = 25;
    long long sum = 45;
    for(int i=6; i<=n; i++){
        dp[i] = sum;
        for(int j=2; j<=i/2; j++){
            dp[i] += dp[i/j];
            dp[i] %= m;
        }
        dp[i] += (i - i/2);
        dp[i] %= m;
        sum += dp[i];
    }
    cout << dp[n];
}
