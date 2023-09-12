#include <iostream>

using namespace std;

long long arr[10001];
long long ans[10001]={0};

int mx(int a,int b){
    if(a>b) return a;
    return b;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        if(i==1) ans[1] = arr[1];
        else if(i==2) ans[2] = arr[1] + arr[2];
        else ans[i] = mx(mx(ans[i-2]+arr[i],ans[i-3] + arr[i-1]+arr[i]),ans[i-1]);
    }
    cout << ans[n] << endl;
}
