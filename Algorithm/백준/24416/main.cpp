#include <iostream>

using namespace std;

int cnt = 0;

int fib(int n) {
    if (n == 1 || n == 2){
        cnt++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int main()
{
    int n;
    cin >> n;
    fib(n);
    cout << cnt << " " << n-2;
}
