#include <iostream>

using namespace std;

long long H[150000];
long long tree[300000];

long long mx(long long a,long long b){
    if(a>b) return a;
    return b;
}

//높이의 최소값을 저장하는 세그먼트리
void init(int node,int L,int R){
    if(L == R) tree[node] = L;
    else{
        init(node*2,L,(L+R)/2);
        init(node*2+1,(L+R)/2+1,R);

        if(H[tree[node*2]] < H[tree[node*2+1]]) tree[node] = tree[node*2];
        else tree[node] = tree[node*2+1];
    }
}

//X ~ Y 구간에서 가장 작은 높이의 index 구하기
int height(int node,int L,int R,int X,int Y){
    if(R < X || Y < L) return -1;
    else if(X <= L && R <= Y) return tree[node];

    int l = height(node*2,L,(L+R)/2,X,Y);
    int r = height(node*2+1,(L+R)/2+1,R,X,Y);

    if(l == -1) return r;
    else if(r == -1) return l;
    else if(H[l] > H[r]) return r;
    else return l;
}

long long Area(int X,int Y,int N){
    int h = height(1,1,N,X,Y);
    long long A = (long long)H[h] * (long long)(Y-X+1);

    if(X < h){
        long long tmp = Area(X,h-1,N);
        A = mx(A,tmp);
    }

    if(h < Y){
        long long tmp = Area(h+1,Y,N);
        A = mx(A,tmp);
    }
    return A;
}

int main()
{
    while(1){
        int n;
        cin >> n;
        if(n==0) break;
        for(int i=1; i<=n; i++){
            cin >> H[i];
        }
        init(1,1,n);
        cout << Area(1,n,n) << "\n";
    }
    return 0;
}
