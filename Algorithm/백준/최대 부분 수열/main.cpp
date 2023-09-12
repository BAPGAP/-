#include <iostream>

using namespace std;

int a[1001]={0};
int ans[1001]={0};
int mx = 0;

int main()
{
    int n;
    int x,y;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x >> y;
        a[x] = y;
    }
    for(int i=1; i<=100; i++){
        int tmp = 0;
        for(int j=i-1; j>0; j--){
            if(a[j] < a[i] && ans[j] > tmp){
                tmp = ans[j];
            }
        }
        ans[i] = tmp+1;
        if(ans[i] > mx) mx = ans[i];
    }
    cout << n - mx;
}
