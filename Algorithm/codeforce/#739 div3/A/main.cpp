#include <iostream>

using namespace std;

int dp[1000];
int cnt = 1;

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    dp[1] = 1;
    dp[2] = 2;
    int cnt = 2;
    int tmp = 2;
    while(cnt <= 1000){
        if(tmp%3==0 || tmp%10 == 3){
            tmp++;
        }
        else{
            dp[cnt] = tmp;
            cnt++;
            tmp++;
        }
    }

    int T;
    cin >> T;
    while(T--){
        int x;
        cin >> x;
        cout << dp[x] << "\n";
    }
}
