#include <iostream>

using namespace std;

int tree[400004] = {0};

int make_tree(int node,int L,int R){
    int M = (L+R)/2;
    if(L == R) return tree[node] = 1;
    else return tree[node] = make_tree(2*node,L,M) + make_tree(2*node+1,M+1,R);
}

void update(int node,int L,int R,int pos){
    if(pos < L || R < pos) return;

    tree[node] -= 1;
    if(L==R) return;
    int M = (L+R)/2;
    update(2*node,L,M,pos);
    update(2*node+1,M+1,R,pos);
}

int gap(int node,int L,int R,int k){
    if(L == R) return L;
    int M = (L+R)/2;
    if(tree[2*node] >= k) return gap(node*2,L,M,k);
    else return gap(node*2+1,M+1,R,k-tree[2*node]);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    make_tree(1,1,n);

    int cnt = n;
    int pos = gap(1,1,n,k);
    cout << "<" << pos;
    update(1,1,n,pos);
    int Plus = k-1;
    k += Plus;
    cnt--;
    if(cnt == 0){
        cout << ">";
        return 0;
    }
    k %= cnt;
    if(k==0) k = cnt;

    while(1){
        pos = gap(1,1,n,k);
        cout << ", " << pos;
        update(1,1,n,pos);
        cnt--;
        if(cnt == 0) break;
        k += Plus;
        k %= cnt;
        if(k == 0) k = cnt;
    }
    cout << ">";
}
