#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int z=0,o=0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 1) o++;
        else z++;
    }
    if(z > o) cout << "Junhee is not cute!";
    else cout << "Junhee is cute!";
}
