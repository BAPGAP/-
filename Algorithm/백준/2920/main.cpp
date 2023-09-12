#include <iostream>

using namespace std;

int main()
{
    bool A = true;
    bool D = true;
    int x;
    for(int i=1; i<=8; i++){
        cin >> x;
        if(x != i) A = false;
        if(x != 9 - i) D = false;
    }
    if(A) cout << "ascending";
    else if(D) cout << "descending";
    else cout << "mixed";
}
