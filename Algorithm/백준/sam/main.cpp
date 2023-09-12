#include <iostream>

using namespace std;

long long pac[2000003];
long long Answer;
long long P = 1000000007;

long long Pow(long long x,long long y){
    if(y == 1) return x;
    else if(y%2 == 1) return (x * Pow(x,y-1)) % P;
    else{
        x = (x*x) % P;
        return Pow(x,y/2);
    }
}

void make(){
    pac[0] = 1;
    for(int i=1; i<=2000002; i++){
        pac[i] = (pac[i-1] * i) % P;
    }
}

int main(int argc, char** argv)
{
    make();
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n , m;
        cin >> n >> m;
        Answer = (pac[m+n+2] * Pow((pac[n+1] * pac[m+1])%P,P-2))%P - 1;

		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}
