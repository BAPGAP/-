#include <iostream>

using namespace std;

int a[11];

int main()
{
    int n;
    cin >> n;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    a[4] = 7;
    for(int i=5; i<=10; i++){
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        cout << a[x] << "\n";
    }
}
