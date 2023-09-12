#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll a[301][301] = {0};
ll n,l;
ll p = 100030001;

ll A(int n,int l){

    if(n==0) return 1;
    if(l==0) return 0;
    if(a[n][l] != -1) return a[n][l];

    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += A(i,l-1) * A(n-1-i,l-1);
        sum %= p;
    }
    return a[n][l] = sum;
}


int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(a,-1,sizeof(a));

    cin >> n >> l;
    cout << (A(n,l) - A(n,l-1) + p)%p;
}
