#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<pair<int,int>> vp;

int tree[2000004];

int make_tree(int node,int L,int R){
    int M = (L+R)/2;
    if(L == R && L == 0) return tree[node] = 0;
    else if(L == R) return tree[node] = 1;
    else return tree[node] = make_tree(2*node,L,M) + make_tree(2*node+1,M+1,R);
}

int tv(int node,int L,int R,int l,int r){
    int M = (L+R)/2;
    if(r < L || R < l) return 0;
    else if(l <= L && R <= r) return tree[node];
    else return tv(2*node,L,M,l,r) + tv(2*node+1,M+1,R,l,r);
}

void update(int node,int L,int R,int pos){
    int M = (L+R)/2;
    if(pos < L || R < pos) return;
    else{
        tree[node] -= 1;
        if(L == R) return;
        update(2*node,L,M,pos);
        update(2*node+1,M+1,R,pos);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vp.push_back({x,i});
    }
    stable_sort(vp.begin(),vp.end());

    make_tree(1,0,n);

    long long sum = 0;

    for(int i=0; i<n; i++){
        int tmp = vp[i].second;
        sum += (long long)tv(1,0,n,0,tmp-1);
        update(1,0,n,tmp);
    }

    cout << sum << "\n";
}
