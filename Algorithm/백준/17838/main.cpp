#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        if(s.size() == 7){
            if(s[0] == s[1] && s[1] == s[4]){
                if(s[2] == s[3] && s[3] == s[5] && s[5] == s[6] && s[2] != s[0]){
                    cout << "1\n";
                }
                else cout << "0\n";
            }
            else cout << "0\n";
        }
        else cout << "0\n";
    }
}
