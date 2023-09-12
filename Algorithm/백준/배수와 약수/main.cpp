#include <iostream>

using namespace std;

int main()
{
    int x,y;
    while(1){
        cin >> x >> y;
        if(x == y) break;
        else if(y % x == 0) cout << "factor\n";
        else if(x % y == 0) cout << "multiple\n";
        else cout << "neither\n";
    }
}
