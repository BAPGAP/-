#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(b > a) return gcd(b,a);
    if(b == 0) return a;
    if(a % b == 0) return b;
    return gcd(b,a%b);
}

int main()
{
    int n;
    cin >> n;
    int a,x;
    cin >> a;
    for(int i=1; i<n; i++){
        cin >> x;
        int z = gcd(a,x);
        cout << a/z << "/" << x/z << "\n";
    }
}
