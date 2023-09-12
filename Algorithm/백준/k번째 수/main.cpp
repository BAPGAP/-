#include <iostream>

using namespace std;

int mn(int a,int b){
    if(a > b) return b;
    return a;
}

int check(long long n,long long k,long long x){
    long long cnt = 0;

    for(long long i=1; i<=n; i++){
        cnt += mn(n,x/i);
    }

    if(cnt >= k) return 1;
    return 0;
}

int main()
{
    long long n,k;
    cin >> n >> k;
    long long L = 1;
    long long R = k;

    while(1){
        if(L == R){
            cout << L;
            break;
        }
        else if(R - L == 1){
            if(check(n,k,L)){
                cout << L;
                break;
            }
            else{
                cout << R;
                break;
            }
        }

        int tmp = check(n,k,(L+R)/2);
        if(tmp){
            R = (L+R)/2;
        }
        else{
            L = (L+R)/2+1;
        }
    }
}
