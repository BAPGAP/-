#include <iostream>

using namespace std;
int n,q;
int a[200001];
int tree[800004];

int make_tree(int node,int x,int y){
    if(x+1 == y) return tree[node] = a[x];
    else if(x < y){
        return tree[node] = make_tree(2*node,x,(x+y)/2) ^ make_tree(2*node+1,(x+y)/2,y);
    }
}

int gap(int node,int x,int y,int l,int r){
    if(r <= x || y <= l) return 0;
    else if(l <= x && y <= r) return tree[node];
    else return gap(2*node,x,(x+y)/2,l,r) ^ gap(2*node+1,(x+y)/2,y,l,r);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for(int i=1; i<n; i++){
        cin >> a[i];
    }

    make_tree(1,1,n);

    for(int i=0; i<q; i++){
        int x,a,b,c;
        cin >> x;
        if(x == 0){
            cin >> a >> b;
            cout << gap(1,1,n,a,b) << "\n";
        }
        else{
            cin >> a >> b >> c;
            int d = c ^ gap(1,1,n,a,b);
            cout << d << "\n";
        }
    }
}
