#include <iostream>

using namespace std;

int main()
{
    string s;
    while(1){
        cin >> s;
        if(s == "0") break;
        int len = s.size();
        bool ok = true;
        for(int i=0; i<len/2; i++){
            if(s[i] != s[len-1 - i]){
                ok = false;
                break;
            }
        }
        if(ok) cout << "yes\n";
        else cout << "no\n";
    }
}
