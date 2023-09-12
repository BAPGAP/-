#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    while(1){
        int x,y;
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        if(x > y) cout << "Yes\n";
        else cout << "No\n";
    }
}
