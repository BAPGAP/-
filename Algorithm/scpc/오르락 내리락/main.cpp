#include <iostream>

using namespace std;

int go[1000001];
long long sum[1000001];

void gogo(){
    go[1] = 0;
    sum[0] = 0;
	sum[1] = 0;

	for(int i=2; i<=1000000; i++){
        if(i%2 == 0) go[i] = go[i/2] + 1;
        else go[i] = go[(i+1)/2] + 2;
        sum[i] = sum[i-1] + go[i];
	}
}

int main(int argc, char** argv)
{
    int T, test_case;

	gogo();

	cin >> T;

	for(test_case = 0; test_case  < T; test_case++)
	{

		int n1,n2;
		cin >> n1 >> n2;
        long long Answer = sum[n2] - sum[n1-1];
		cout << "Case #" << test_case+1 << "\n" << Answer << "\n";
	}

	return 0;
}
