#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        int L=0;
        int R=0;
        int ok = 1;
        for(int j=0; j<s.size(); j++){
            if(s[j] == '(') L++;
            else R++;

            if(L < R) ok = 0;
        }
        if(L != R) ok = 0;

        if(ok == 0) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}
