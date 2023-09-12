#include <iostream>

using namespace std;

int mx(int a,int b){
    if(a>b) return a;
    else return b;
}

int main()
{
    int arr[301]={0};
    int ans[301]={0};
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        if(i==1) ans[i] = arr[i];
        else if(i==2) ans[i] = arr[i] + arr[i-1];
        else{
            ans[i] = mx(ans[i-3] + arr[i-1] + arr[i],ans[i-2] + arr[i]);
        }
    }
    cout << ans[n] << endl;
}
