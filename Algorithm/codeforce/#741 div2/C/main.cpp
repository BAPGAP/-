#include <iostream>

using namespace std;

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool ok = false;
        for(int i=n/2; i<n; i++){
            if(s[i] == '0'){
                cout << "1 " << i+1 << " 1 " << i << "\n";
                ok = true;
                break;
            }
        }

        if(ok) continue;

        for(int i=n/2-1; i>=0; i--){
            if(s[i] == '0'){
                cout << i+1 << " " << n << " " << i+2 << " " << n << "\n";
                ok = true;
                break;
            }
        }

        if(ok) continue;

        cout << "1 " << n-1 << " 2 " << n << "\n";
    }
}
