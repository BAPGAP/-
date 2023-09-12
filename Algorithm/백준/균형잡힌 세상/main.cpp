#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while(1){
        getline(cin, s);
        if(s == ".") break;
        char c[101];
        int cnt = 0;
        int ok = 1;
        for(int j=0; j<s.size(); j++){
            if(s[j] == '('){c[cnt] = s[j]; cnt++;}
            else if(s[j] == '['){c[cnt] = s[j]; cnt++;}
            else if(s[j] == ')'){
                if(cnt == 0){
                    ok = 0;
                    break;
                }
                else if(c[cnt-1] == '(') cnt--;
                else{
                    ok = 0;
                    break;
                }
            }
            else if(s[j] == ']'){
                if(cnt == 0){
                    ok = 0;
                    break;
                }
                else if(c[cnt-1] == '[') cnt--;
                else{
                    ok = 0;
                    break;
                }
            }
        }
        if(cnt != 0) cout << "no" << "\n";
        else if(ok == 1){
            cout << "yes" << "\n";
        }
        else cout << "no" << "\n";
    }
}
