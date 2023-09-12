#include <iostream>

using namespace std;

int main()
{
    int n,x;
    int mx,mn;
    cin >> n;
    cin >> x;
    mx = x;
    mn = x;
    for(int i=1; i<n; i++){
        cin >> x;
        if(x > mx) mx = x;
        if(x < mn) mn = x;
    }
    cout << mx * mn <<endl;
}
