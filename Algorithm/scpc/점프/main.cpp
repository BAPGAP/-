#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long Answer;
long long x,y;
long long F[500000] = {0};
long long jump[2000];
long long K = sqrt(20) * 100000;

long long big(long long tmp){
    long long T_q = tmp - K;
    long long g = floor(sqrt(2*T_q+1)-0.5);
    long long hap = g*(g+1)/2;

    if(hap != T_q){
        g++;
        hap += g;
    }

    long long A = 100000000000;

    while(tmp > hap){
        A = min(A,g + F[tmp - hap]);
        g++;
        hap += g;
    }
    return A;
}

int main(int argc, char** argv)
{
    jump[0] = 0;
    for(int i=1; i<= 1001; i++){
        jump[i] = jump[i-1] + i;
    }

    int cnt = 0;
    while(jump[cnt] <= K){
        F[jump[cnt]] = cnt;
        cnt++;
    }

    for(int i=2; i <= K; i++){
        if(F[i] == 0){
            F[i] = F[i-1] + 1;
            for(int j = 1; j < 1000; j++){
                if(jump[j] > i) break;
                F[i] = min(F[i],j + F[i - jump[j]]);
            }
        }
    }


	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		cin >> x >> y;
		Answer = 0;

        long long tmp = floor(sqrt(2*y+1)-0.5);
        long long pos = (tmp-1) * tmp / 2;

        for(long long i = y; i >= max(x,pos); i--){
            if(i > K) Answer = max(Answer,big(i));
            else Answer = max(Answer,F[i]);
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
