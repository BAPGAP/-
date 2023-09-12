#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a[200001];
int b[200001];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n;
	    cin >> n;
	    for(int i=0; i<n; i++){
            cin >> a[i];
	    }
        for(int i=0; i<n; i++){
            cin >> b[i];
	    }
	    sort(a,a+n);
	    sort(b,b+n);
	    long long mx = 0;
	    long long pos = 0;
        for(int i=0; i<n; i++){
            long long tmp = abs(a[i] - b[i]);
            if(tmp > mx){
                mx = tmp;
                pos = i;
            }
        }
        int pos1; //b[pos]가 a에있다면? a에서의 위치 찾을거임
        int L = 0;
        int R = n-1;
        if(a[R] <= b[pos]) a[pos] = b[R];
        else{
            while(1){
                if(L == R || a[L] == a[R]){
                    pos1 = R;
                    break;
                }
                int M = (L+R)/2;
                if(a[M] <= b[pos]) L = M;
                else R = M-1;
            }
            a[pos] = b[pos1];
        }
        sort(a,a+n);

        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += abs(a[i] - b[i]);
        }
		cout << "Case #" << test_case+1 << "\n" << sum << endl;
	}

	return 0;
}
