#include <iostream>

using namespace std;

long long H[100001];
long long mx = 0;

long long mn(long long a,long long b){
    if(a > b) return b;
    return a;
}
long long mnx(long long a,long long b){
    if(a > b) return a;
    return b;
}

// [L,R]에서 M포함 최대값 찾는 함수
void m(long long M,long long L,long long R){
    long long L_ = M;
    long long R_ = M;
    long long h = H[M];
    while(1){
        if(L_ < L && R_ > R) return;

        for(int i=L_; i>=L; i--){
            if(H[i] < h){
                L_ = i;
                break;
            }
            if(i == L) L_--;
        }
        for(int i=R_; i<=R; i++){
            if(H[i] < h){
                R_ = i;
                break;
            }
            if(i == R) R_++;
        }
        if((R_-L_-1) * h > mx) mx = (R_-L_-1) * h;

        if(L_ < L) h = mn(H[R_],h);
        else if(R_ > R) h = mn(H[L_],h);
        else h = mn(mnx(H[L_],H[R_]),h);
    }
}

void lr(long long L,long long R){
    if(L>R){
        return;
    }
    if(L == R){
        if(H[L] > mx) mx = H[L];
        return;
    }
    long long M = (L+R)/2;
    m(M,L,R);
    lr(L,M-1);
    lr(M+1,R);
}


int main()
{
    int n;
    while(1){
        cin >> n;
        if(n == 0) return 0;
        for(int i=1; i<=n; i++){
            cin >> H[i];
        }
        mx = 0;
        lr(1,n);
        cout << mx << "\n";
    }
}
