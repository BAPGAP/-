#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int c = 0;
    while(n > 0){
        if(n%2 == 1) c++;
        n >>= 1;
    }
    cout << c;
}
