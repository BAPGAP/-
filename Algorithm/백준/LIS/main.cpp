#include <iostream>

using namespace std;

int a[501];
int l[501];

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        l[1] = 1;
        for(int i=2; i<=n; i++){
            int mx = 1;
            for(int j=1; j<i; j++){
                if(a[j] < a[i]) mx = max(mx,l[j]+1);
            }
            l[i] = mx;
        }
        int mx=l[1];
        for(int i=2; i<=n; i++){
            mx = max(mx,l[i]);
        }
        cout << mx << "\n";
    }
}
