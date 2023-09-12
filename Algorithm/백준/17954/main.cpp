#include <iostream>

using namespace std;

long long a[3][10001];

int main()
{
    int n;
    cin >> n;

    if(n == 1){
        cout << "2\n1\n2";
        return 0;
    }
    if(n == 2){
        cout << "35\n1 2\n3 4";
        return 0;
    }
    long long sum = (2*n + 1)*n;

    a[1][1] = 2*n;
    a[1][n] = 2*n-1;
    a[2][1] = 2*n-2;
    a[2][n] = 2*n-3;
    for(int i=2; i<=n-1; i++){
        a[1][i] = i-1;
        a[2][i] = i + n - 3;
    }
    long long Answer = 0;
    for(long long i=0; i<n-1; i++){
        Answer += i * sum;
        sum -= a[2][n-i];
    }
    Answer += (n-1) * sum;
    sum -= a[2][1];
    Answer += n * sum;
    sum -= a[1][n];
    for(long long i=n+1; i<2*n-1; i++){
        Answer += i * sum;
        sum -= a[1][2*n-i];
    }
    Answer += (2*n-1) * sum;
    cout << Answer << "\n";
    cout << a[1][1];
    for(int i=2; i<=n; i++){
        cout << " " << a[1][i];
    }
    cout << "\n" << a[2][1];
    for(int i=2; i<=n; i++){
        cout << " " << a[2][i];
    }
    return 0;
}
