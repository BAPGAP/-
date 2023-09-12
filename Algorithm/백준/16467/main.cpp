#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll p = 1e8 + 7;

vector<vector<ll>> gop(vector<vector<ll>> a,vector<vector<ll>> b){
    int l = a.size();
    vector<vector<ll>> answer;
    for(int i=0; i<l; i++){
        vector<ll> tmp;
        for(int j=0; j<l; j++){
            ll in = 0;
            for(int k=0; k<l; k++){
                in += (a[i][k] * b[k][j])%p;
                in %= p;
            }
            tmp.push_back(in);
        }
        answer.push_back(tmp);
    }
    return answer;
}

vector<vector<ll>> go(vector<vector<ll>> v,int k,int n){
    if(n == 1) return v;
    else if(n%2){
        return gop(v,go(gop(v,v),k,(n-1)/2));
    }
    else{
        return go(gop(v,v),k,n/2);
    }
}

long long two(long long n){
    if(n==1) return 2;
    else if(n%2){
        return (2 * (two((n-1)/2) * two((n-1)/2))%p)%p;
    }
    else{
        return (two(n/2) * two(n/2))%p;
    }
}

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        ll k,n;
        cin >> k >> n;
        if(k >= n){
            cout << "1\n";
            continue;
        }
        else if(k==0){
            //2^n
            cout << two(n) << "\n";
            continue;
        }
        vector<vector<ll>> v;
        vector<ll> tmp;
        for(int i=0; i<=k; i++){
            if(i == 0 || i == k) tmp.push_back(1);
            else tmp.push_back(0);
        }
        v.push_back(tmp);
        for(int i=1; i<=k; i++){
            vector<ll>().swap(tmp);
            for(int j=0; j<=k; j++){
                if(j == i-1) tmp.push_back(1);
                else tmp.push_back(0);
            }
            v.push_back(tmp);
        }
        v = go(v,k,n-k);
        ll answer = 0;
        for(int i=0; i<=k; i++){
            answer += v[0][i];
            answer %= p;
        }
        cout << answer << "\n";
    }
}
