#include <iostream>

using namespace std;

int main()
{
    int sum;
    cin >> sum;
    int x;
    for(int i=0; i<9; i++){
        cin >> x;
        sum -= x;
    }
    cout << sum;
}
