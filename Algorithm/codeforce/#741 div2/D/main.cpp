#include <iostream>
#include <vector>

using namespace std;

string s;

vector<pair<int,int>> tree(600006);

pair<int,int> make_tree(int node,int L,int R){
    if(L == R){
        if(L%2 == 1){
            if(s[L] == '-') s[L] = '+';
            else s[L] = '-';
        }
        if(s[L] == '+'){
            return tree[node] = {1,0};
        }
        else return tree[node] = {0,1};
    }
    else{
        int M = (L+R)/2;
        pair<int,int> x = make_tree(2*node,L,M);
        pair<int,int> y = make_tree(2*node+1,M+1,R);
        return tree[node] = {x.first+y.first,x.second+y.second};
    }
}

pair<int,int> gap(int node,int L,int R,int l,int r){
    if(r < L || R < l) return pair<int,int>{0,0};
    else if(l <= L && R <= r) return tree[node];
    else{
        int M = (L+R)/2;
        pair<int,int> x = gap(2*node,L,M,l,r);
        pair<int,int> y = gap(2*node+1,M+1,R,l,r);
        return tree[node] = {x.first+y.first,x.second+y.second};
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
        cin >> s;
        make_tree(1,0,n-1);
        for(int i=0; i<q; i++){
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            pair<int,int> tmp = gap(1,0,n-1,x,y);
            cout << abs(tmp.first - tmp.second) << "\n";
        }
    }
}
