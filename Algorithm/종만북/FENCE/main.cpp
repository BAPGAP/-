#include <iostream>

using namespace std;

int F[20001];
int tree[80004];
int n;

int make_tree(int node,int L,int R){
    if(L == R) return tree[node] = L;
    else if(L < R){
        int M = (L+R)/2;
        int L_val = make_tree(2*node,L,M);
        int R_val = make_tree(2*node+1,M+1,R);
        if(F[L_val] > F[R_val]) return tree[node] = R_val;
        else return tree[node] = L_val;
    }
}

int return_min(int node,int L,int R,int l,int r){
    if(R < l || r < L) return -1;
    else if(l <= L && R <= r) return tree[node];
    else{
        int M = (L+R)/2;
        int L_val = return_min(2*node,L,M,l,r);
        int R_val = return_min(2*node+1,M+1,R,l,r);
        if(L_val < 0) return R_val;
        else if(R_val < 0) return L_val;
        else{
            if(F[L_val] < F[R_val]) return L_val;
            else return R_val;
        }
    }
}

int sum = 0;

void gogo(int L,int R){
    if(L > R) return;
    int height_pos = return_min(1,1,n,L,R);
    int area = (R - L + 1) * F[height_pos];
    if(area > sum) sum = area;
    gogo(L,height_pos-1);
    gogo(height_pos+1,R);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> F[i];
        }
        make_tree(1,1,n);
        sum = 0;
        gogo(1,n);
        cout << sum << "\n";
    }
}
