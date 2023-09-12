#include <iostream>

using namespace std;

int dp[10001] = {0};

int main()
{
    int n,M;
    int sum = 0;
    cin >> n >> M;
    int m[101];
    int c[101];
    for(int i=1; i<=n; i++){
        cin >> m[i];
    }
    for(int i=1; i<=n; i++){
        cin >> c[i];
        sum += c[i];
    }
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=sum; j>=c[i]; j--){
            if(dp[j] < dp[j-c[i]] + m[i]) dp[j] = dp[j-c[i]] + m[i];
        }
    }
    for(int i=1; i<=sum; i++){
        if(dp[i] >= M){
            cout << i;
            break;
        }
    }
}
