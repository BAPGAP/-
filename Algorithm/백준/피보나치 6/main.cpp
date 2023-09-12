#include <iostream>
#define NUM 1000000007

using namespace std;
typedef long long L;

L* a = new L[5];
L* ans = new L[5];

L* gop(L* x, L* y){
    L* tmp = new L[5];
    for(int i=1; i<=2; i++){
        for(int j=1; j<=2; j++){
            int sum = 0;
            for(int k=1; k<=2; k++){
                sum += (x[2*(i-1)+k] * y[2*(k-1)+j])%NUM;
            }
            tmp[2*(i-1)+j] = sum % NUM;
        }
    }
    return tmp;
}


void pow(long long n){

    if(n == 1){
        ans = gop(ans,a);
        return;
    }

    if(n%2 == 1){
        ans = gop(ans,a);
        pow(n-1);
    }
    else{
        a = gop(a,a);
        pow(n/2);
    }
}


int main()
{
    long long B;
    cin >> B;

    ans[1] = 1;
    ans[2] = 0;
    ans[3] = 0;
    ans[4] = 1;

    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    a[4] = 0;

    pow(B);

    cout << ans[3];
}
