#include <iostream>

using namespace std;



long long pac(int x){
    if(x == 1) return 1;
    if(x == 2) return 2;
    if(x == 3) return 6;
    if(x == 4) return 24;

    long long A = (x * (x-1))%1000000007;
    A = (A * (x-2))%1000000007;
    A = (A * (x-3))%1000000007;

    return (A * pac(x-4))%1000000007;
}


int main()
{
    int n;
    cin >> n;
    cout << pac(n);

}
