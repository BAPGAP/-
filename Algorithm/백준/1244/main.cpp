#include <iostream>

using namespace std;

int s[101];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int x;
        cin >> x;
        if(x == 1){
            int t;
            cin >> t;
            for(int j=t; j<=n; j+=t){
                s[j] = 1 - s[j];
            }
        }
        else{
            int t;
            cin >> t;
            s[t] = 1 - s[t];
            for(int j=1; j<=n; j++){
                if(t+j > n || t-j < 1) break;
                else if(s[t+j] != s[t-j]) break;
                else{
                    s[t+j] = 1 - s[t+j];
                    s[t-j] = 1 - s[t-j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << s[i] << " ";
        if(i%20 == 0) cout << "\n";
    }
}
