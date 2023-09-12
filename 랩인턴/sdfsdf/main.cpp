#include <iostream>

using namespace std;

int func(int x) {
int a = x | (x >> 16) | (x << 16);
int b = a | (a >> 8) | (a << 8);
int c = b | (b >> 4) | (b << 4);
int d = c | (c >> 2) | (c << 2);
int e = d | (d >> 1) | (d << 1);
return e;
}

int main()
{
    cout << func(3) << endl;
    return 0;
}
