#include <iostream>

using namespace std;
typedef long long ll;

ll a[100001];

int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        ll n,k;
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        ll Answer = -987654321;
        for(ll j=2; j<=n; j++){
            for(ll i = max(j-2*k,1LL); i<j; i++){
                ll tmp = i * j - k * (a[i] | a[j]);
                if(tmp > Answer) Answer = tmp;
            }
        }
        cout << Answer << "\n";
    }
}
