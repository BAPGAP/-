#include <iostream>

using namespace std;

int main()
{
    int x;
    int sum = 0;
    for(int i=0; i<5; i++){
        cin >> x;
        x %= 10;
        sum += x*x;
        sum %= 10;
    }
    cout << sum;
}
