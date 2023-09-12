#include <iostream>

using namespace std;

long long a[1001];

int main()
{
    int n;
    cin >> n;
    a[1] = 1;
    a[2] = 2;
    for(int i=3; i<=n; i++){
        a[i] = (a[i-1] + a[i-2])%10007;
    }
    cout << a[n] << "\n";
}
