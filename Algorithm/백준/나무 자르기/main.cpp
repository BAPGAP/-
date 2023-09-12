#include <iostream>

using namespace std;

long long h[1000010];
long long M;

int check(int N,long long H,long long M){
    long long sum = 0;
    for(int i=1; i<=N; i++){
       if(h[i] >= H) sum += h[i] - H;
    }
    if(sum >= M) return 1;
    else return 0;
}


int main()
{
    int N;
    long long mx=0;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> h[i];
        if(h[i] > mx) mx = h[i];
    }

    long long L = 0;
    long long R = mx;

    while(1){
        if(L == R){
            cout << L;
            break;
        }
        if(R - L == 1){
            if(check(N,R,M)){
                cout << R;
                break;
            }
            cout << L;
            break;
        }
        int tmp = check(N,(L+R)/2,M);
        if(tmp){
            L = (L+R)/2;
        }
        else R = (L+R)/2-1;
    }
}
