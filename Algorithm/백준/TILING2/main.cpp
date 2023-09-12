#include <iostream>

using namespace std;

long long p = 1e9 + 7;
long long dp[101];

int main()
{
    int T;
    cin >> T;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<101; i++){
        dp[i] = (dp[i-1] + dp[i-2])%p;
    }

    while(T--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}
