#include <iostream>

using namespace std;

int main()
{
    int s = 0;
    for(int i=0; i<10; i++){
        int n;
        cin >> n;
        if(n == 1) s += 1;
        else if(n == 2) s += 2;
        else s -= 1;
    }
    s = s+20;
    s = s%4;
    if(s == 0) cout << "N";
    else if(s == 1) cout << "E";
    else if(s == 2) cout << "S";
    else cout << "W";
}
