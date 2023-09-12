#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<pair<ll,ll>> cave;

bool compare(pair<ll,ll> x,pair<ll,ll> y){
    if(x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        for(ll i=0; i<n; i++){
            ll num;
            cin >> num;
            ll mx = -1;
            for(ll j=0; j<num; j++){
                ll x;
                cin >> x;
                if(x-j+1 > mx){
                    mx = x-j+1;
                }
            }
            cave.push_back({mx,mx+num});
        }
        sort(cave.begin(),cave.end(),compare);

        ll mn = cave[0].first;
        ll pass = cave[0].second;
        ll sum = pass - mn;
        for(ll i=1; i<cave.size(); i++){
            ll tmp = cave[i].second - cave[i].first;
            if(pass >= cave[i].first){
                pass += tmp;
            }
            else{
                mn = cave[i].first - sum;
                pass = cave[i].second;
            }
            sum += tmp;
        }

        cout << mn << "\n";
        vector<pair<ll,ll>>().swap(cave);
    }
}
