#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

//Answer = n-k+1 C k - n-k-1 C k-2

ll p = 1000000003;//소수 아님!!!! 10억7이 제일 가까운 소수 그다음 10억9

ll C[1001][1001];

ll combi(ll a,ll b){
    if(a < b) return 0;
    if(b == 0 || a == b) return 1;
    if(C[a][b] != -1) return C[a][b];
    return C[a][b] = (combi(a-1,b-1) + combi(a-1,b))%p;
}

int main()
{
    ll n,k;
    cin >> n >> k;
    if(n < 2*k) cout << "0";
    else if(k == 1) cout << n;
    else{
        memset(C,-1,sizeof C);
        ll Answer = combi(n-k+1,k);
        Answer = (Answer - combi(n-k-1,k-2))%p;
        if(Answer < 0) Answer += p;
        cout << Answer;
    }
}
