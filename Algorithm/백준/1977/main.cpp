#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n,m;
    cin >> n >> m;
    if(n == (int)sqrt(n) * (int)sqrt(n)) n = (int)sqrt(n);
    else n = (int)sqrt(n) + 1;
    m = (int)sqrt(m);
    if(n > m) cout << "-1";
    else{
        long long sum = m * (m+1) * (2*m+1) / 6 - (n-1)*n*(2*n-1) / 6;
        cout << sum << "\n";
        cout << n * n;
    }
}
