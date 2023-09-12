#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long sum = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            long long x;
            cin >> x;
            sum += x;
        }
    }
    cout << sum;
}
