#include <iostream>

using namespace std;

int five(int a){
    if(a == 0) return 0;
    return a/5 + five(a/5);
}
int two(int a){
    if(a == 0) return 0;
    return a/2 + two(a/2);
}
int mn(int a,int b){
    if(a>b) return b;
    return a;
}


int main()
{
    int n,m;
    cin >> n >> m;
    cout << mn(five(n) - five(m) - five(n-m),two(n)-two(m)-two(n-m));
}
