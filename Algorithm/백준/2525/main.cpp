#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int sum = (a * 60 + b + c)%1440;
    int h = sum/60;
    int m = sum%60;
    cout << h << " " << m;
}
