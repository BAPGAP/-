#include <iostream>

using namespace std;

long long a[101];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        long long mn = 9987654321;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            if(a[i] < mn){
                mn = a[i];
            }
        }
        bool ok = true;
        while(ok){
            ok = false;
            for(int i=1; i<=n; i++){
                if((mn & a[i]) < mn){
                    mn = mn & a[i];
                    ok = true;
                    break;
                }
            }
        }
        cout << mn << "\n";
    }
}
