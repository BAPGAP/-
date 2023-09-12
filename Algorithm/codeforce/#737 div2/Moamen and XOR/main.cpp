#include <iostream>

using namespace std;

long long p = 1000000007;

long long pow(long long x,long long y){
    if(y == 0) return 1;
    if(y == 1) return x;
    long long tmp = (x*x)%p;
    if(y%2 == 1) return (x * pow(tmp,y/2))%p;
    else return pow(tmp,y/2);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        long long n,k;
        cin >> n >> k;
        if(k == 0) cout << "1\n";
        else if(n%2 == 0){
            long long tmp = pow(2,n-1); //a1
            long long a1 = tmp;
            for(int i=2; i<=k; i++){
                tmp = pow(2,n*(i-1)) + ((a1-1) * tmp)%p;
                tmp %= p;
            }
            cout << tmp << "\n";
        }
        else{
            long long tmp = (pow(2,n-1) + 1)%p;
            long long a1 = tmp;
            for(int i=2; i<=k; i++){
                tmp *= a1;
                tmp %= p;
            }
            cout << tmp << "\n";
        }
    }
}
