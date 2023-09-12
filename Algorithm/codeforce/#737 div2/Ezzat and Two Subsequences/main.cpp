#include <iostream>
#include <algorithm>

using namespace std;

long double a[100000];
long double sum;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n;
        cin >> n;
        sum = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }
        sort(a,a+n);
        sum -= a[n-1];
        cout << fixed;
        cout.precision(8);
        cout << a[n-1] + sum / (n-1) << "\n";
    }
}
