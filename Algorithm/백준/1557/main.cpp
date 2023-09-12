#include <iostream>
#include <cmath>

using namespace std;

int mx = 1000000000;

int gop[100000];

int main()
{
    for(int i=2; i*i<=mx; i++){
        gop[i] = i*i;
    }

    int k;
    cin >> k;

    int sum = 0;
    for(int i=2; i*i<=k; i++){
        sum += k/gop[i];
    }
}
