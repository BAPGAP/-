#include <iostream>

using namespace std;

int main()
{
    int x,mx,sum = 1;
    int n;
    cin >> n;
    cin >> x;
    mx = x;
    for(int i=1; i<n; i++){
        cin >> x;
        if(mx >= x) mx = x;
        else {sum++; mx = x;}
    }
    cout << sum << endl;
}
