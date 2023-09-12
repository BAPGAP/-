#include <iostream>

using namespace std;

int arr[501] = {0};
int ans[501] = {0};

int mn(int a,int b){
    if(a > b) return a;
    else return b;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> arr[j];
        }
        for(int j=1; j<=i; j++){
            arr[j] = mn(ans[j-1],ans[j]) + arr[j];
        }
        for(int j=1; j<=i; j++){
            ans[j] = arr[j];
        }
    }

    int mx=ans[1];
    for(int i=2; i<=n; i++){
        if(ans[i] > mx) mx = ans[i];
    }
    cout << mx << endl;
}
