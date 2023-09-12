#include <iostream>
#include <string>

using namespace std;

bool dp[10001][3] = {0};

int main()
{
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    int a,b;
    cin >> a >> b;
    string S = "ab";
    S[0] = s1[a];
    S[1] = s1[b];
    string s = s1.substr(0,a) + s1.substr(a+1,b-a-1) + s1.substr(b+1,n-b-1);

    //s , S 합쳐서 s2만들기
    dp[0][0] = true;
    dp[0][1] = S[0] == s2[0];
    dp[1][0] = s[0] == s2[0];
    for(int i=2; i<=n; i++){
        if(i <= n-2) dp[i][0] = dp[i-1][0] && (s[i-1] == s2[i-1]);
        if(i <= n-1) dp[i-1][1] = (dp[i-1][0] && (S[0] == s2[i-1])) || (dp[i-2][1] && (s[i-2] == s2[i-1]));
        dp[i-2][2] = (dp[i-2][1] && (S[1] == s2[i-1])) || (dp[i-3][2] && (s[i-3] == s2[i-1]));
    }
    if(dp[n-2][2]) cout << "YES";
    else cout << "NO";
}
