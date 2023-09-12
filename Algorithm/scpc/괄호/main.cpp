#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int Answer;
int dp[1000001];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        string s;
        cin >> s;
        stack<char> v;

        for(int i=0; i<s.size(); i++){
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(v.empty()){
                    dp[i] = 0;
                }
                else{
                    char tmp = v.top();
                    v.pop();
                    if(tmp == '(' && s[i] == ')'){
                        dp[i] = dp[i-1] + 1;
                        for(int j= i - 2 * dp[i]; ;j -= 2*dp[j]){
                            if(dp[j] != 0){
                                dp[i] += dp[j];
                            }
                            else break;
                        }
                    }
                    else if(tmp == '{' && s[i] == '}'){
                        dp[i] = dp[i-1] + 1;
                        for(int j= i - 2 * dp[i]; ;j -= 2*dp[j]){
                            if(dp[j] != 0){
                                dp[i] += dp[j];
                            }
                            else break;
                        }
                    }
                    else if(tmp == '[' && s[i] == ']'){
                        dp[i] = dp[i-1] + 1;
                        for(int j= i - 2 * dp[i]; ;j -= 2*dp[j]){
                            if(dp[j] != 0){
                                dp[i] += dp[j];
                            }
                            else break;
                        }
                    }
                    else{
                        dp[i] = 0;
                        while(!v.empty()){
                            v.pop();
                        }
                    }
                }
            }
            else{
                v.push(s[i]);
                dp[i] = 0;
            }
        }

        Answer = 0;
        for(int i=0; i<s.size(); i++){
            Answer = max(Answer,dp[i]);
        }
		cout << "Case #" << test_case+1 << endl << 2 * Answer << endl;
	}

	return 0;
}
