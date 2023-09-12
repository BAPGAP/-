#include <iostream>

using namespace std;

int dp[1001][10] = {0}; //n일차 떡이 x번일때 경로 존재 여부

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        for(int j=1; j<=x; j++){
            int y;
            cin >> y;
            if(i==1) dp[i][y] = 1;
            else{
                for(int k=1; k<=9; k++){
                    if(k != y) dp[i][y] += dp[i-1][k];
                }
                if(dp[i][y] > 1) dp[i][y] = 1;
            }
        }
    }
    int sum = 0;
    for(int i=1; i<=9; i++){
        sum += dp[n][i];
    }
    if(sum == 0) cout << "-1";
    else{
        string answer = "";
        int e;
        for(int i=1; i<=9; i++){
            if(dp[n][i] == 1){
                e = i;
                answer += to_string(i);
                break;
            }
        }
        for(int i=n-1; i>=1; i--){
            for(int j=1; j<=9; j++){
                if(dp[i][j] == 1 && e != j){
                    e = j;
                    answer += to_string(j);
                    break;
                }
            }
        }
        for(int i=answer.size()-1; i>=0; i--){
            cout << answer[i] << "\n";
        }
    }
}
