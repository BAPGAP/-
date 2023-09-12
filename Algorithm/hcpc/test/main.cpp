#include <iostream>
#include <vector>

using namespace std;

string s[100001];
long long dp[100001][7] = {0};
long long p = 1e9 + 7;

string gogo = "UNIST";

vector<pair<string,int>> vs;

int main()
{
    for(int i=0; i<5; i++){
        for(int j=i; j<5; j++){
            string tmp = gogo.substr(i,j-i+1);
            vs.push_back({tmp,i});
        }
    }

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    for(int i=0; i<n; i++){
        if(i!=0){
            for(int j=0; j<5; j++){
                dp[i][j] = dp[i-1][j];
            }
        }

        for(int j=0; j<vs.size(); j++){
            string unist = vs[j].first;
            int len = unist.size();

            string tmp = s[i].substr(0,len);

            if(tmp == unist){
                int start = vs[j].second;
                //start ~ start+len-1 ±îÁö ¸¸µë
                if(i == 0){
                    if(start == 0){
                        dp[i][len-1] += 1;
                    }
                }
                else{
                    dp[i][start+len-1] += dp[i-1][start-1];
                    dp[i][start+len-1] %= p;
                }
            }
        }
    }
    cout << dp[n-1][4];
}
