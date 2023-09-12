#include <iostream>
#include <string>

using namespace std;

int Answer;
int n,t;
int b[50001];
int a[50001];
string s;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    cin >> n >> t;
	    cin >> s;
	    for(int i=1; i<=n; i++){
            b[i] = s[i-1] - '0';
            a[i] = -1;
	    }
	    for(int i=1; i<=n; i++){
            if(b[i] == 0){
                if(i+t <= n) a[i+t] = 0;
                if(i-t > 0) a[i-t] = 0;
            }
	    }
	    for(int i=1; i<=n; i++){
            if(b[i] == 1){
                if(i-t <= 0) a[i+t] = 1;
                else if(i+t > n) a[i-t] = 1;
                else{
                    if(a[i-t] == -1 && a[i+t] != -1){
                        a[i-t] = 1 - a[i+t];
                    }
                    else if(a[i+t] == -1 && a[i-t] != -1){
                        a[i+t] = 1 - a[i-t];
                    }
                }
            }
	    }
	    for(int i=t+1; i+t<=n; i++){
            if(a[i] == -1){
                a[i] = 0;
                for(int j=i+2*t; j<=n; j+=2*t){
                    if(a[j] == -1) a[j] = 1-a[j-2*t];
                    else break;
                }
            }
	    }

        for(int i=1; i<=n; i++){
            if(a[i] == 0) s[i-1] = '0';
            else s[i-1] = '1';
		}

		cout << "Case #" << test_case+1 << endl;

		cout << s << "\n";
	}

	return 0;
}
