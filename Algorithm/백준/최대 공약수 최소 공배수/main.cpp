#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(a%b==0) return b;

    if(2 * b > a) return gcd(b,a-b);
    else return gcd(a-b,b);
}

int main()
{
    int x,y,n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        if(x>y) cout << (x*y)/gcd(x,y) << "\n";
        else cout << (x*y)/gcd(y,x) << "\n";
    }

}
