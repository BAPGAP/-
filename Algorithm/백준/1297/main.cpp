#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a > c) swap(a,c);
    if(b > c) swap(b,c);
    cout << 2*c - a - b;
}
