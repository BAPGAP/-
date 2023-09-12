#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int A[200001];
int B[200001];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n,k;
        cin >> n >> k;
        for(int i=0; i<n; i++){
            cin >> A[i];
        }
        for(int i=0; i<n; i++){
            cin >> B[i];
        }
        sort(A,A+n);
        sort(B,B+n);

        Answer = A[0] + B[k-1];

        for(int i=1; i<k; i++){
            Answer = max(Answer,A[i]+B[k-1-i]);
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
