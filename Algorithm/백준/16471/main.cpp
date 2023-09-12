#include <iostream>
#include <algorithm>

using namespace std;

int a[200000];
int b[200000];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int L = 0;
    int R = 0;
    int cnt = 0;
    while(L < n && R < n){
        if(a[L] >= b[R]) R++;
        else{
            L++;
            R++;
            cnt++;
        }
    }
    if(cnt >= n/2+1) cout << "YES";
    else cout << "NO";
}
