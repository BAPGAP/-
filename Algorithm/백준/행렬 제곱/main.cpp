#include <iostream>

using namespace std;

int* a = new int[26];
int* ans = new int[26];

int* gop(int* x, int* y,int Size){
    int* tmp = new int[Size * Size + 1];
    for(int i=1; i<=Size; i++){
        for(int j=1; j<=Size; j++){
            int sum = 0;
            for(int k=1; k<=Size; k++){
                sum += (x[Size*(i-1)+k] * y[Size*(k-1)+j])%1000;
            }
            tmp[Size*(i-1)+j] = sum % 1000;
        }
    }
    return tmp;
}


void pow(long long n, int Size){

    if(n == 1){
        ans = gop(ans,a,Size);
        return;
    }

    if(n%2 == 1){
        ans = gop(ans,a,Size);
        pow(n-1,Size);
    }
    else{
        a = gop(a,a,Size);
        pow(n/2,Size);
    }
}


int main()
{
    int N;
    long long B;
    cin >> N >> B;
    for(int i=1; i<=N*N; i++){
        cin >> a[i];
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) ans[N*(i-1)+j] = 1;
            else ans[N*(i-1)+j] = 0;
        }
    }
    pow(B,N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << ans[N*(i-1)+j] << " ";
        }
        cout << "\n";
    }
}
