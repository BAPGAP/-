#include <iostream>

// ������ ���� ���� ���Ҽ� �ִ� �ڷᱸ��
// �� ���ҵ� �����Ӱ� �ٲܼ��ִ�.
using namespace std;

int a[100];
int tree[201];

// tree �����
int init(int node,int L,int R){
    if(L == R) return tree[node] = a[L];
    return tree[node] = init(node*2,L,(L+R)/2) + init(node*2+1,(L+R)/2+1,R);
}

// X ~ Y ������ �� ���ϱ� L, R�� node�� ����ϴ� ����
int sum(int node,int L,int R,int X,int Y){
    if(R < X || Y < L) return 0;
    if(X <= L && R <= Y) return tree[node];
    return sum(node*2,L,(L+R)/2,X,Y) + sum(node*2+1,(L+R)/2+1,R,X,Y);
}

// ���� �����ϱ� M��° ���� ���� tmp = �ٲ�� - ������
void edit(int node,int L,int R,int M,int tmp){
    if(M < L || R < M) return;
    tree[node] += tmp;
    if(L != R){
        edit(node*2,L,(L+R)/2,M,tmp);
        edit(node*2+1,(L+R)/2+1,R,M,tmp);
    }
}


int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    init(1,1,n);
    for(int i=1; i<=2*n+1; i++){
        cout << tree[i] << " ";
    }
    cout << "\n" << sum(1,1,n,3,8);
    edit(1,1,n,5,3);
    cout << "\n";
    for(int i=1; i<=2*n+1; i++){
        cout << tree[i] << " ";
    }
}
