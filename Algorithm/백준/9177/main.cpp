#include <iostream>
#include <cstring>

using namespace std;

string x,y,z;

bool dp[201][201] = {0};

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int cnt = 1;
    while(T--){
        cin >> x >> y >> z;
        cout << "Data set " << cnt++;

        dp[0][0] = true;
        for(int i=1; i<=y.size(); i++){
            dp[0][i] = z[i-1] == y[i-1];
        }
        for(int i=1; i<=x.size(); i++){
            dp[i][0] = z[i-1] == x[i-1];
        }
        for(int i=1; i<=x.size(); i++){
            for(int j=1; j<=y.size(); j++){
                dp[i][j] = (dp[i-1][j] && x[i-1] == z[i+j-1]) || (dp[i][j-1] && y[j-1] == z[i+j-1]);
            }
        }


        if(dp[x.size()][y.size()]) cout << ": yes";
        else cout << ": no";
        cout << "\n";
    }
}
