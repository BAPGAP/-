#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int Answer;
int N = 1000000001;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n;
	    cin >> n;
        Answer = N;
	    if(n == 1 || n == 2){
            cout << "Case #" << test_case+1 << endl;
            cout << n+1 << endl;
            continue;
	    }
	    int mx_b = pow(10,5);
	    int mx_i;
	    for(int b=2; b<min(mx_b,n); b++){
            for(int i=0; i<=30; i++){
                if(pow(b,i) > n){
                    mx_i = i;
                    break;
                }
            }
            if(n % (((int)pow(b,mx_i) - 1)/(b-1)) == 0 && n / (((int)pow(b,mx_i) - 1)/(b-1)) < b){
                Answer = b;
                break;
            }
	    }
	    /*if(Answer == N){
            for(int b=mx_b; b<n; b++){
                if(n % (1+b) == 0){
                    Answer = b;
                    break;
                }
            }
	    }*/

        cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
