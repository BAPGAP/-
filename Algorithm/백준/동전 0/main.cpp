#include <iostream>

using namespace std;

int a[11];

int main()
{
    int n,k,sum=0;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=n; i>0; i--){
        while(1){
            if(k >= a[i]){
                k -= a[i];
                sum++;
            }
            else break;
        }
    }
    cout << sum << endl;
}
