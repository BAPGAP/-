#include <iostream>

using namespace std;

int a[1000001];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int mx = -1;
    for(int i=0; ; i++){
        int two = 1 << i;
        if(two > 1000000) break;
        int sum = 0;
        for(int j=0; j<n; j++){
            if(two&a[j]) sum += 1;
        }
        if(sum > mx) mx = sum;
    }
    cout << mx;
}
