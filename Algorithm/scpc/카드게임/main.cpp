#include <iostream>

using namespace std;

int dp[3001][3001];
int dp_x_sum[3001][3001];
int dp_y_sum[3001][3001];
int sum1[3001];
int sum2[3001];
int cnt1;
int cnt2;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n,k;
        int x;
        cin >> n >> k;
        sum1[0] = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            sum1[i+1] = sum1[i] + x;
        }
        sum2[0] = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            sum2[i+1] = sum2[i] + x;
        }

        dp[0][0] = 1;
        dp_x_sum[0][0] = 1;
        dp_y_sum[0][0] = 1;

        int x_point = 0;
        int y_point = 0;

        for(int i=0; i<=n; i++){

            while(1){
                if(sum2[i] - sum2[y_point] <= k) break;
                y_point++;
            }

            x_point = 0;

            for(int j=0; j<=n; j++){
                if(i == 0 && j == 0) continue;

                while(1){
                    if(sum1[j] - sum1[x_point] <= k) break;
                    x_point++;
                }

                if(i == 0){
                    if(x_point == 0){
                        if(dp_x_sum[i][j-1] == j){
                            dp[i][j] = 0;
                            dp_x_sum[i][j] = dp_x_sum[i][j-1];
                        }
                        else{
                            dp[i][j] = 1;
                            dp_x_sum[i][j] = dp_x_sum[i][j-1] + 1;
                        }
                    }
                    else if(dp_x_sum[i][j-1] - dp_x_sum[i][x_point-1] == j - x_point){
                        dp[i][j] = 0;
                        dp_x_sum[i][j] = dp_x_sum[i][j-1];
                    }
                    else{
                        dp[i][j] = 1;
                        dp_x_sum[i][j] = dp_x_sum[i][j-1] + 1;
                    }
                    dp_y_sum[i][j] = dp[i][j];
                }
                else if(j == 0){
                    if(y_point == 0){
                        if(dp_y_sum[i-1][j] == i){
                            dp[i][j] = 0;
                            dp_y_sum[i][j] = dp_y_sum[i-1][j];
                        }
                        else{
                            dp[i][j] = 1;
                            dp_y_sum[i][j] = dp_y_sum[i-1][j] + 1;
                        }
                    }
                    else if(dp_y_sum[i-1][j] - dp_y_sum[y_point-1][j] == i - y_point){
                        dp[i][j] = 0;
                        dp_y_sum[i][j] = dp_y_sum[i-1][j];
                    }
                    else{
                        dp[i][j] = 1;
                        dp_y_sum[i][j] = dp_y_sum[i-1][j] + 1;
                    }
                    dp_x_sum[i][j] = dp[i][j];
                }
                else{
                    if(x_point + y_point == 0){
                        if(dp_x_sum[i][j-1] + dp_y_sum[i-1][j] == j + i){
                            dp[i][j] = 0;
                            dp_x_sum[i][j] = dp_x_sum[i][j-1];
                            dp_y_sum[i][j] = dp_y_sum[i-1][j];
                        }
                        else{
                            dp[i][j] = 1;
                            dp_x_sum[i][j] = dp_x_sum[i][j-1] + 1;
                            dp_y_sum[i][j] = dp_y_sum[i-1][j] + 1;
                        }
                    }
                    else if(x_point == 0){
                        if(dp_x_sum[i][j-1] + dp_y_sum[i-1][j] - dp_y_sum[y_point-1][j] == j + i - y_point){
                            //모두 1
                            dp[i][j] = 0;
                            dp_x_sum[i][j] = dp_x_sum[i][j-1];
                            dp_y_sum[i][j] = dp_y_sum[i-1][j];
                        }
                        else{
                            dp[i][j] = 1;
                            dp_x_sum[i][j] = dp_x_sum[i][j-1] + 1;
                            dp_y_sum[i][j] = dp_y_sum[i-1][j] + 1;
                        }
                    }
                    else if(y_point == 0){
                        if(dp_x_sum[i][j-1] - dp_x_sum[i][x_point-1] + dp_y_sum[i-1][j] == j - x_point + i){
                            //모두 1
                            dp[i][j] = 0;
                            dp_x_sum[i][j] = dp_x_sum[i][j-1];
                            dp_y_sum[i][j] = dp_y_sum[i-1][j];
                        }
                        else{
                            dp[i][j] = 1;
                            dp_x_sum[i][j] = dp_x_sum[i][j-1] + 1;
                            dp_y_sum[i][j] = dp_y_sum[i-1][j] + 1;
                        }
                    }
                    else{
                        if(dp_x_sum[i][j-1] - dp_x_sum[i][x_point-1] + dp_y_sum[i-1][j] - dp_y_sum[y_point-1][j] == j - x_point + i - y_point){
                            //모두 1
                            dp[i][j] = 0;
                            dp_x_sum[i][j] = dp_x_sum[i][j-1];
                            dp_y_sum[i][j] = dp_y_sum[i-1][j];
                        }
                        else{
                            dp[i][j] = 1;
                            dp_x_sum[i][j] = dp_x_sum[i][j-1] + 1;
                            dp_y_sum[i][j] = dp_y_sum[i-1][j] + 1;
                        }
                    }
                }
            }
        }

        cnt1 = cnt2 = 0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(dp[i][j] == 0) cnt2++;
                else cnt1++;
            }
        }

		cout << "Case #" << test_case+1 << endl;
		cout << cnt1 << " " << cnt2 << endl;
	}

	return 0;
}
