#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

int a[101];
int sum[101];
int sum_2[101];
int dp[101][101];


int score(int n,int i){
    int diff = sum[n] - sum[n-i];
    int m = int(0.5+(double)diff/i);
    int answer = sum_2[n] - sum_2[n-i] + m*m*i - 2*m*diff;
    return answer;
}

int gogo(int n,int m){
    int& ret = dp[n][m];
    if(ret != -1) return ret;

    ret = 987654321;

    if(n==0) return ret = 0;
    if(m==0 && n>0) return ret;

    for(int i=1; i<=n; i++){
        ret = min(ret,gogo(n-i,m-1) + score(n,i));
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        memset(dp,-1,sizeof(dp));
        int n,m;
        cin >> n >> m; //n개의 숫자를 m개 숫자로 표현
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        sum[0] = 0;
        sum_2[0] = 0;
        for(int i=1; i<=n; i++){
            sum[i] = sum[i-1] + a[i];
            sum_2[i] = sum_2[i-1] + a[i]*a[i];
        }
        cout << gogo(n,m) << "\n";
    }
}
