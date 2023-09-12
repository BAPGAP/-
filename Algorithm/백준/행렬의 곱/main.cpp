#include <iostream>

using namespace std;

int a[501];
int b[501];
int p[501][501] = {0}; // p[a][b]는 a ~ b 까지 책 합치는 비용 최소.

int mn(int a,int b){
    if(a > b) return b;
    return a;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i=1; i<n; i++){
        for(int j=1; i+j<=n; j++){
            p[j][j+i] = 2147483647;
            for(int k=j; k<j+i; k++){
                if(p[j][j+i] > p[j][k]+p[k+1][j+i]+a[j]*b[k]*b[i+j]){
                    p[j][j+i] = p[j][k]+p[k+1][j+i]+a[j]*b[k]*b[i+j];
                }
            }
        }
    }
    cout << p[1][n] << "\n";
}
