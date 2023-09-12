/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    Answer = 0;
	    int a[101] = {0};
	    int n,k;
        cin >> n >> k;
        int x;
        for(int i=0; i<n; i++){
            cin >> x;
            a[x]++;
        }
		for(int i=100; i>=0; i--){
		    if(k <= 0) break;
		    else if(a[i] == 0) continue;
		    else if(k >= a[i]){
		        k -= a[i];
		        Answer += i * a[i];
		    }
		    else{
		        Answer += i * k;
		        k = 0;
		    }
		}

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
