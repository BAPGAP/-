#include <iostream>

using namespace std;

int tri[10000] = {0};


int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=1; i<=10000; i++){
        tri[i] = tri[i-1] + i;
    }
    int T;
    cin >> T;
    while(T--){
        int n,k;
        cin >>n >> k;
        int sum = (n-1)/k;
        int L = 0;
        int R = 10000;
        int M;
        while(L < R){
            if(L +1 == R){
                if(tri[R]<=sum) L = R;
                else R = L;
            }
            M = (L+R)/2;
            if(tri[M] <= sum) L = M;
            else R = M-1;
        }
        M = (L+R)/2;
        int remain = (n-1) - k*tri[M];
        if(M%2){ //L
            cout << k*(M+1)/2 - remain << " L\n";
        }
        else{
            cout << -k*M/2 + remain << " R\n";
        }
    }

}
