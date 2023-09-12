#include <iostream>

using namespace std;
int looped (int a[], int n) {
    int i;
    int x = 0;

    for(i = 0; x < n; i++) {
        if (x < a[i])
            x = a[i];
    }
    return x;
}
int main()
{
    int a[15] = {8,5,1,4,2,3,10,15};
    cout << looped(a,14);
}
