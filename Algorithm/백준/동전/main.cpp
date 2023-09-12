#include <iostream>
using namespace std;
int main()
{
    int a[10001] = {0};
    int n,k,x;
    cin >> n >> k;
    a[0] = 1;
    for(int i=0; i<n; i++){
        cin >> x;
        for(int j=x; j<=k; j++){
            a[j] += a[j-x];
        }
    }
    cout << a[k];
}
