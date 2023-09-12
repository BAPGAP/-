#include <iostream>

using namespace std;

int tree[2000001] = {0};
int lazy[2000001] = {0};

void lazy_update(int node,int L,int R){
    tree[node] += lazy[node] * (R-L+1);
    if(L != R){
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node,int L,int R,int l,int r){
    if(lazy[node]) lazy_update(node,L,R);

    if(R < l || r < L) return;
    else if(l <= L && R <= r){
        lazy[node] += 1;
    }
    else{
        int M = (L+R)/2;
        update(2*node,L,M,l,r);
        update(2*node+1,M+1,R,l,r);
    }
}

int gap(int node,int L,int R,int l,int r){
    if(lazy[node]) lazy_update(node,L,R);

    if(R < l || r < L) return 0;
    else if(l <= L && R <= r){
        return tree[node];
    }
    else{
        int M = (L+R)/2;
        return gap(2*node,L,M,l,r) + gap(2*node+1,M+1,R,l,r);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,h;
    cin >> n >> h;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(i%2) update(1,1,h,h-x+1,h);
        else update(1,1,h,1,x);
    }

    int mn = 987654321;
    int cnt = 0;

    for(int i=1; i<=h; i++){
        int tmp = gap(1,1,h,i,i);
        if(tmp < mn){
            mn = tmp;
            cnt = 1;
        }
        else if(tmp == mn) cnt++;
    }
    cout << mn << " " << cnt;
}
