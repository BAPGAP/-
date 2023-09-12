#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    char s[8];
        int a,b,c;
        cin >> a >> b >> c;
        for(int i=0; i<c; i++){
            int n,k;
            cin >> n >> k;
            if(a > b){
                if(2 <= n && n <= a) s[i] = 'b';
                else if(a+1 <= n && n <= a*k+b) s[i] = 'a';
                else if(a*k+b+1 <= n && n <= 2*a + b*k) s[i] = 'b';
                else s[i] = 'a';
            }
            else{
                int d = n % (a*k+a);
                if(1 <= d && d <= a) s[i] = 'b';
                else s[i] = 'a';
            }
        }
		cout << "Case #" << test_case+1 << endl;
		for(int i=0; i<c; i++){
            cout << s[i];
		}
		cout << endl;
	}

	return 0;
}
