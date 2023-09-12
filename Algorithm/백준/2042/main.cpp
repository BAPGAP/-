#include <iostream>

using namespace std;

typedef long long ll;

ll a[1000000];
ll tree[4000000];
ll p = 1000000007;

ll maketree(int node,int L,int R){
    if(L == R) return tree[node] = a[L];
    else{
        int M = (L+R)/2;
        return tree[node] = (maketree(2*node,L,M) * maketree(2*node+1,M+1,R))%p;
    }
}

ll update(int node,int L,int R,int locate){
    if(locate < L || R < locate) return tree[node];
    else if(L == R && L == locate) return tree[node] = a[L];
    else{
        int M = (L+R)/2;
        return tree[node] = (update(2*node,L,M,locate) * update(2*node+1,M+1,R,locate))%p;
    }
}

ll gap(int node,int L,int R,int l,int r){
    int M = (L+R)/2;
    if(r < L || R < l) return 1;
    else if(l <= L && R <= r) return tree[node];
    else return (gap(2*node,L,M,l,r) * gap(2*node+1,M+1,R,l,r))%p;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,m,k;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    maketree(1,0,n-1);
    while(m || k){
        ll x,y,z;
        cin >> x >> y >> z;
        if(x==1){
            //y번째수를 z
            y--;
            a[y] = z;
            update(1,0,n-1,y);
            m--;
        }
        else{
            y--;
            z--;
            cout << gap(1,0,n-1,y,z) << "\n";
            k--;
        }
    }
}
