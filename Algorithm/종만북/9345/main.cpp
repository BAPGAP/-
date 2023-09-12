#include <iostream>

using namespace std;

int tree[2][400000];
int book[100000];
int INF[2] = {987654321,0};

int make_tree(int node,int L,int R,int type){
    int M = (L+R)/2;
    if(L == R){
        book[L] = L;
        return tree[type][node] = L;
    }
    else{
        if(type) return tree[type][node] = max(make_tree(node*2,L,M,type),make_tree(node*2+1,M+1,R,type));
        else return tree[type][node] = min(make_tree(node*2,L,M,type),make_tree(node*2+1,M+1,R,type));
    }
}

int gap(int node,int L,int R,int l,int r,int type){
    int M = (L+R)/2;
    if(r < L || R < l) return INF[type];
    else if(l <= L && R <= r) return tree[type][node];
    else{
        if(type) return max(gap(node*2,L,M,l,r,type),gap(node*2+1,M+1,R,l,r,type));
        else return min(gap(node*2,L,M,l,r,type),gap(node*2+1,M+1,R,l,r,type));
    }
}

int update(int node,int L,int R,int pos,int type){
    int M = (L+R)/2;
    if(pos < L || R < pos) return tree[type][node];
    else{
        if(L == R){
            return tree[type][node] = book[L];
        }
        else{
            if(type) return tree[type][node] = max(update(node*2,L,M,pos,type),update(node*2+1,M+1,R,pos,type));
            else return tree[type][node] = min(update(node*2,L,M,pos,type),update(node*2+1,M+1,R,pos,type));
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int n,q;
        cin >> n >> q;
        make_tree(1,0,n-1,1);
        make_tree(1,0,n-1,0);

        for(int i=0; i<q; i++){
            int x,y,z;
            cin >> x >> y >> z;
            if(x){
                int mx = gap(1,0,n-1,y,z,1);
                int mn = gap(1,0,n-1,y,z,0);
                if(mx == z && mn == y) cout << "YES\n";
                else cout << "NO\n";
            }
            else{
                swap(book[y],book[z]);
                for(int t=0; t<=1; t++){
                    update(1,0,n-1,y,t);
                    update(1,0,n-1,z,t);
                }
            }
        }
    }
}
