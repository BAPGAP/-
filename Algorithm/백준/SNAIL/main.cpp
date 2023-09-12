#include <iostream>
#include <cstring>

using namespace std;

int n,m; //n을 m일동안

double dp[1001][2002]; //dp[x][y]는 x일이전에 y올라갈 확률

double gogo(int x,int y){

    if(y <= 0) return 1;

    double& ret = dp[x][y];
    if(ret > -1) return ret;

    if(x == 0) return ret = 0;

    ret = 0.75 * gogo(x-1,y-2) + 0.25 * gogo(x-1,y-1);

    return ret;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        memset(dp,-1,sizeof(dp));
        cin >> n >> m;
        dp[0][0] = 0;
        cout.precision(8);
        cout << gogo(m,n) << "\n";
    }
}
