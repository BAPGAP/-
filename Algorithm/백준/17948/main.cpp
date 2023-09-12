#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;
long long oil, build;
long long adress[5001];
long long sum[5001];

long long dp[5001][2]; //dp[나눠야 할 사람 명수][0:cost  1:cnt]

long long cost(int n,int i){ //adress[n-i+1] ~ adress[n]
    long long answer = (sum[n] - sum[n-i+i/2+i%2]) - (sum[n-i+i/2] - sum[n-i]);
    answer *= oil;
    return answer;
}

long long gogo(int n){

    long long& ret = dp[n][0];
    if(ret != -1) return ret;

    ret = LLONG_MAX;

    int ok = 0;
    for(int i=n; i>=1; i--){
        long long tmp = gogo(n-i) + cost(n,i) + build;
        if(ret > tmp && tmp > 0){
            ret = tmp;
            ok = n-i;
        }
    }
    dp[n][1] = dp[ok][1] + 1;
    return ret;
}

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> adress[i];
    }
    sort(adress+1,adress+n+1);

    sum[0] = 0;
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + adress[i];
    }

    cin >> oil >> build;

    dp[0][0] = 0;
    dp[0][1] = 0;

     cout << gogo(n) << " " << dp[n][1];
}
