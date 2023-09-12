#include <iostream>

using namespace std;

long long a[200001];
long long tree[400002];

long long gcd(long long x,long long y){
    if(y == 0) return x;
    else return gcd(y,x%y);
}

long long gap(int n,long long l,long long r){ //[l,r)
    long long tmp = 0;
    for(l += n,r += n; l<r; l >>= 1, r >>= 1){
        if(l & 1) tmp = gcd(tree[l++],tmp);
        if(r & 1) tmp = gcd(tree[--r],tmp);
    }
    return tmp;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=n-1; i<2*n-2; i++){
            tree[i] = abs(a[i-n+2] - a[i-n+1]);
        }
        for(int i=n-2; i>=1; i--){
            tree[i] = gcd(tree[i << 1],tree[i << 1 | 1]);
        }
        //현재 세그 트리 구간 0 ~ n-2 여기서 값이 2이상인 최대 구간 찾을 거임
        int Answer = 0;
        for(int i=0; i<n-1; i++){
            int L = i+1;
            int R = n-1;
            while(L <= R){
                int M = (L + R)/2;
                long long tmp = gap(n-1,i,M);
                if(tmp > 1){
                    if(Answer < M - i) Answer = M - i;
                    L = M+1;
                }
                else R = M-1;
            }
        }
        cout << Answer+1 << "\n";
    }
}
