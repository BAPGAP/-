#include <iostream>
#include <cstring>

using namespace std;

long long n;
long long a[16];
long long k;
long long pac[16];
long long len[16] = {0};
long long dp[1 << 16][100]; //dp[방문상태][나머지] = 나머지의 개수
long long ten[51]; // 10^x를 k로 나눈 나머지

long long dfs(int visit,int remain){ //지금까지 방문상태는 visit 그때 나머지
    if(visit == (1 << n) - 1){
        if(remain) return 0;
        else return 1;
    }
    if(dp[visit][remain] != -1) return dp[visit][remain];

    dp[visit][remain] = 0;

    for(int i=0; i<n; i++){
        if(visit & (1 << i)) continue;
        dp[visit][remain] += dfs(visit | (1 << i),((remain * ten[len[i]])%k + a[i])%k);
    }

    return dp[visit][remain];
}

long long gcd(long long a, long long b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

string s[16];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    pac[0] = 1;
    for(int i=0; i<n; i++){
        cin >> s[i];
        pac[i+1] = pac[i] * (i+1);
        len[i] = s[i].size();
    }
    cin >> k;

    for(int i=0; i<n; i++){
        a[i] = s[i][0] - '0';
        long long T = 10 % k;
        for(int j=1; j<len[i]; j++){
            a[i] = a[i] * T + (s[i][j] - '0');
            a[i] %= k;
        }
    }
    ten[1] = 10 % k;
    for(int i=2; i<=50; i++){
        ten[i] = (ten[i-1] * 10) % k;
    }
    memset(dp,-1,sizeof dp);
    long long cnt = dfs(0,0);
    if(cnt == 0){
        cout << "0/1";
        return 0;
    }
    long long G = gcd(cnt,pac[n]);
    cout << cnt/G << "/" << pac[n]/G;
}
