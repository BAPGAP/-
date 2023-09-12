#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];

int main()
{
    int n,l;
    cin >> n >> l;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=0; i<n; i++){
        if(l >= a[i]) l++;
        else{
            cout << l;
            return 0;
        }
    }
    cout << l;
}
