#include <iostream>

using namespace std;

long long dol[50001][101];
long long sum[50001];
bool check[50001];


int main(int argc, char** argv)
{
    for(int i=1; i<=100; i++){
        dol[0][i] = 0;
    }
    dol[0][0] = 1;
    sum[0] = 1;

	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n,k,l;
	    int x;
	    cin >> n >> k >> l;

        for(int i=1; i<=n; i++){
            sum[i] = 0;
            check[i] = false;
        }
        check[0] = false;
	    for(int i=0; i<l; i++){
            cin >> x;
            check[x] = true;
	    }

	    for(int i=1; i<=n; i++){
            if(check[i]) continue;
            for(int j=1; j<=k; j++){ //차이
                if(check[i-j]) dol[i][j] = 0;
                else if(i >= j){
                    dol[i][j] = sum[i-j] - dol[i-j][j]; //같은 걸음수는 안돼요!
                    sum[i] = (sum[i] + dol[i][j]) % 1000000009;
                }
                else dol[i][j] = 0;
            }
	    }

        if(sum[n] < 0) sum[n] += 1000000009;

		cout << "Case #" << test_case+1 << endl;
		cout << sum[n] << endl;
	}

	return 0;
}
