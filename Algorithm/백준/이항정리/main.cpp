#include <iostream>

using namespace std;

int main()
{
    int n,k;
    int mo=1, ja=1;
    cin >> n >> k;
    for(int i=0; i<k; i++){
        ja *= (n-i);
        mo *= (k-i);
    }
    cout << ja/mo << endl;
}
