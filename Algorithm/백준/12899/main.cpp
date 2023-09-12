#include <iostream>

using namespace std;

int ed = 2000000;
int tree[8000004] = {0};

void update(int node,int L,int R,int pos,int x){
    if(pos < L || R < pos) return;

    tree[node] += x;

    if(L != R){
        int M = (L+R)/2;
        update(2*node,L,M,pos,x);
        update(2*node+1,M+1,R,pos,x);
    }
}

int gap(int node,int L,int R,int k){
    if(L == R) return L;
    int M = (L+R)/2;

    if(tree[2*node] >= k) return gap(2*node,L,M,k);
    else return gap(2*node+1,M+1,R,k-tree[node*2]);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        if(x==1){
            update(1,1,ed,y,1);
        }
        else{
            int tmp = gap(1,1,ed,y);
            cout << tmp << "\n";
            update(1,1,ed,tmp,-1);
        }
    }
}
