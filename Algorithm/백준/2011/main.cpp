#include <iostream>
#include <cstring>
#include <string>

using namespace std;

long long dp[5001];
long long p = 1e6;
string s;

long long gogo(int x){
    long long& tmp = dp[x];
    if(tmp != -1) return tmp;

    tmp = 0;

    if(x >= 1){
        string one = "";
        one = s.substr(x-1,1);
        if(one != "0"){
            tmp += gogo(x-1);
            tmp %= p;
        }
    }
    if(x >= 2){
        string two = "";
        two = s.substr(x-2,2);
        int gap = stoi(two);
        if(10 <= gap && gap <= 26){
            tmp += gogo(x-2);
            tmp %= p;
        }
    }
    return tmp;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> s;
    dp[0] = 1;
    cout << gogo(s.size());
}
