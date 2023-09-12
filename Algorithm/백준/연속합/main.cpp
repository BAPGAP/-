#include <iostream>

using namespace std;

long long sum;
long long mx;

int main()
{
    int n;
    int x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        if(i==0) {mx = x; sum = x;}
        else{
            if(sum + x >= x){
                sum += x;
            }
            else sum = x;
            if(sum > mx) mx = sum;
        }
    }
    cout << mx << endl;
}
