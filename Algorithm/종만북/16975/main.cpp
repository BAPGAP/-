#include <iostream>

using namespace std;

long long a[100001];
long long tree[400004];
long long lazy[400004] = {0};


long long make_tree(int node,int L,int R){
    int M = (L+R)/2;
    if(L == R) return tree[node] = a[L];
    else return tree[node] = make_tree(node*2,L,M) + make_tree(node*2+1,M+1,R);
}

void lazy_update(int node,int L,int R){
    tree[node] += lazy[node] * (R-L+1);
    if(L != R){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

long long gap(int node,int L,int R,int pos){
    if(lazy[node] != 0) lazy_update(node,L,R);

    if(pos < L || R < pos) return 0;
    else{
        int M = (L+R)/2;
        if(L == R) return tree[node];
        else  return gap(node*2,L,M,pos) + gap(node*2+1,M+1,R,pos);
    }
}

void update(int node,int L,int R,int l,int r,long long tmp){
    if(lazy[node] != 0) lazy_update(node,L,R);

    if(r < L || R < l) return;
    else if(l <= L && R <= r){
        lazy[node] += tmp;
        lazy_update(node,L,R);
    }
    else{
        int M = (L+R)/2;
        update(node*2,L,M,l,r,tmp);
        update(node*2+1,M+1,R,l,r,tmp);
        tree[node] = tree[node*2] + tree[node*2+1]; //Áß¿ä!!
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    make_tree(1,1,n);

    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        if(x == 1){
            int y,z,k;
            cin >> y >> z >> k;
            update(1,1,n,y,z,k);
        }
        else{
            int y;
            cin >> y;
            cout << gap(1,1,n,y) << "\n";
        }
    }
}
