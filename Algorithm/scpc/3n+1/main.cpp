#include <iostream>
#include <cmath>

using namespace std;

int cnt;

int go(int x){
    if(x == 1) return 1;
    cnt++;
    if(x%2 == 0) return x/2;
    else return (3*x+1);
}


int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int k;
	    cin >> k;
        int tmp;
	    int mn = 1;

	    while(1){
            tmp = mn;
            cnt = 0;
            while(1){
                tmp = go(tmp);
                if(tmp == 1) break;
            }
            if(k == cnt) break;
            mn++;
	    }


	    unsigned long long ans = pow(2,k);

		cout << "Case #" << test_case+1 << "\n";
		cout << mn << " " << ans << "\n";
	}

	return 0;
}
