#include <iostream>
#include <algorithm>

using namespace std;

int P[10001];
int Q[10001];
int dp[10001];


int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> P[i];
        }

        for(int i=0; i<n; i++){
            cin >> Q[i];
        }
        dp[0] = max(P[0],Q[0]);
        dp[1] = max(dp[0]+P[1],Q[1]);

        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1]+P[i],dp[i-2]+Q[i]);
        }
        cout << "Case #" << test_case+1 << endl;
		cout << dp[n-1] << endl;
	}

	return 0;
}
