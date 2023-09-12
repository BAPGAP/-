#include <iostream>
#include <cmath>

using namespace std;

long double a[501];
long double sum[501];

int main()
{
    int n,k;
    cin >> n >> k;
    sum[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    long double Answer = 987654321;
    for(int i=1; i<=n-k+1; i++){
        for(int j=i+k-1; j<=n; j++){
            long double tmp = 0;
            long double m = (sum[j] - sum[i-1])/(j-i+1);
            for(int l=i; l<=j; l++){
                tmp += (a[l] - m) * (a[l] - m);
            }
            tmp = sqrt(tmp/(j-i+1));
            if(Answer > tmp) Answer = tmp;
        }
    }
    cout << fixed;
    cout.precision(7);
    cout << Answer;
}
