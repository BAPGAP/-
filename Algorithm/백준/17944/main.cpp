#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    k = k%(4*n-2);
    if(k <= 2*n) cout << k;
    else cout << 4*n - k;
}
