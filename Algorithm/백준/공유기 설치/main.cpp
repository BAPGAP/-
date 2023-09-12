#include <iostream>

using namespace std;

long long H[200001];
long long H_[200001];

void Merge(int L,int M,int R){
    int cnt = 0;
    int l = L;
    int r = M+1;
    while(1){
        if(l > M || r > R) break;

        if(H[l] > H[r]){
            H_[cnt] = H[r];
            r++;
        }
        else{
            H_[cnt] = H[l];
            l++;
        }
        cnt++;
    }
    if(l > M){
        for(int i=r; i<=R; i++){
            H_[cnt] = H[i];
            cnt++;
        }
    }
    else if(r > R){
        for(int i=l; i<=M; i++){
            H_[cnt] = H[i];
            cnt++;
        }
    }
    for(int i=0; i<cnt; i++){
        H[i+L] = H_[i];
    }
}

void Sort(int L,int R){
    if(L == R) return;
    int M = (L+R)/2;
    Sort(L,M);
    Sort(M+1,R);
    Merge(L,M,R);
}

int check(int n,int c,int x){
    long long p = H[1];
    int cnt = 1;
    for(int i=1; i<=n; i++){
        if(p + x <= H[i]){
            p = H[i];
            cnt++;
        }
    }
    if(cnt >= c) return 1;
    else return 0;
}


int main()
{
    int n,c;
    cin >> n >> c;
    for(int i=1; i<=n; i++){
        cin >> H[i];
    }
    Sort(1,n);

    long long L = 1;
    long long R = H[n];

    while(1){
        if(L == R){
            cout << L;
            break;
        }
        else if(R - L == 1){
            if(check(n,c,R)){
                cout << R;
                break;
            }
            cout << L;
            break;
        }

        int tmp = check(n,c,(L+R)/2);
        if(tmp){
            L = (L+R)/2;
        }
        else{
            R = (L+R)/2 - 1;
        }
    }

}
