#include <iostream>
#include <cmath>

using namespace std;

int dp[100001] = {0};

int go(int n){
    if(dp[n] != 0) return dp[n];
    else if(n == (int)sqrt(n) * (int)sqrt(n)) return dp[n] = 1;
    else{
        int tmp = 987654321;
        for(int i=sqrt(n); i>0; i--){
            tmp = min(tmp,go(n-(i*i))+1);
        }
        return dp[n] = tmp;
    }
}

int main()
{
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    cout << go(n);
}
