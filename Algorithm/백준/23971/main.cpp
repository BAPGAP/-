#include <iostream>

using namespace std;

int main()
{
    int h,w,n,m;
    cin >> h >> w >> n >> m;
    int x = 1 + (h-1)/(n+1);
    int y = 1 + (w-1)/(m+1);
    cout << x * y;
}
