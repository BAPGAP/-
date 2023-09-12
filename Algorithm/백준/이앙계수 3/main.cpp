#include <iostream>
#define NUM 1000000007

using namespace std;

long long pac (int n){
    long long sum = 1;
    for(int i=2; i<=n; i++){
        sum = (sum * i)%NUM;
    }
    return sum;
}

long long pow(long long a,long long b){
    if(b == 0) return 1;
    if(b == 1) return a;
    long long a2 = (a * a) % NUM;
    if(b%2 == 1){
        return (pow(a2, b/2) * a) % NUM;
    }
    return pow(a2,b/2) % NUM;
}


int main()
{
    int n,k;
    cin >> n >> k;
    long long tmp;
    tmp = (pac(k) * pac(n-k))%NUM;
    tmp = pow(tmp,NUM - 2);
    tmp = (tmp * pac(n))%NUM;
    cout << tmp << "\n";
}
