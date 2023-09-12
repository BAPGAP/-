#include <iostream>

using namespace std;

int t[16];
int p[16];
int dp[30] = {0};

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
    }
    for(int i=n; i>0; i--){
        if(i + t[i] - 1 > n) continue;
        int mx = 0;
        for(int j=i+t[i]-1; j>=i; j--){
            if(dp[j] > mx) mx = dp[j];
        }
        dp[i] = p[i] + mx;
    }
    int mx=0;
    for(int i=1; i<=n; i++){
        if(mx < dp[i]) mx = dp[i];
    }
    cout << mx;
}
