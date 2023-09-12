#include <iostream>

using namespace std;

int a[8];
int sum = 0;
int mn = 101;

int main()
{
    for(int i=1; i<=7; i++){
        cin >> a[i];
        if(a[i] % 2 == 1){
            sum += a[i];
            if(mn > a[i]) mn = a[i];
        }
    }
    if(sum == 0) cout << "-1";
    else{
        cout << sum << "\n" << mn;
    }
}
