#include <iostream>
#include <cstring>

using namespace std;

int p = 1e7;

int dp[101][101]; //x개인데 y개로 시작

int gogo(int x,int y){

    int& ret = dp[x][y];
    if(ret != -1) return ret;

    ret = 0;

    if(x == y) return ret = 1;

    for(int i=1; i<=x-y; i++){
        ret += ((y+i-1) * gogo(x-y,i))%p;
        ret %= p;
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        memset(dp,-1,sizeof(dp));
        int n;
        cin >> n;
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum = (sum + gogo(n,i))%p;
        }
        cout << sum << "\n";
    }
}
