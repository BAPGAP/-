#include <iostream>

using namespace std;

int a[501];
int sum[501]; // sum[b]는 a[1] ~ a[b]까지의 합.
int p[501][501] = {0}; // p[a][b]는 a ~ b 까지 책 합치는 비용 최소.
int num[501][501]; // num[a][b]는 a ~ b 까지 구간합을 구하는 점화식에서 값이 최소가 된 k를 저장.

int mn(int a,int b){
    if(a > b) return b;
    return a;
}


int main()
{
    int m;
    cin >> m;
    for(int q=0; q<m; q++){
        int n;
        cin >> n;
        sum[0] = 0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            sum[i] = sum[i-1] + a[i];
            num[i][i] = i;
        }

        for(int i=1; i<n; i++){
            for(int j=1; i+j<=n; j++){
                p[j][j+i] = 2100000000;
                for(int k=num[j][j+i-1]; k<=num[j+1][j+i]; k++){
                    if(p[j][j+i] > p[j][k]+p[k+1][j+i]){
                        p[j][j+i] = p[j][k]+p[k+1][j+i];
                        num[j][j+i] = k;
                    }
                }
                p[j][j+i] += sum[j+i] - sum[j-1];
            }
        }
        cout << p[1][n] << "\n";
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                p[i][j] = 0;
            }
        }
    }
}
