#include <iostream>

using namespace std;

long long a[91]; //0으로 끝남
long long b[91]; //1로 끝남

int main()
{
    int n;
    cin >> n;
    a[1] = 0;
    b[1] = 1;
    a[2] = 1;
    b[2] = 0;
    for(int i=3; i<=n; i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    cout << a[n] + b[n];
}
