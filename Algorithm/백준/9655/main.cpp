#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n%4 == 0 || n%4 == 2) cout << "CY";
    else cout << "SK";
}
