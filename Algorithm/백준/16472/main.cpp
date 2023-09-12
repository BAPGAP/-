#include <iostream>
#include <set>

using namespace std;

int alpha[26] = {0};
set<char> S;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int L = 0;
    int R = 0;
    int mx = min(n,(int)s.size());
    while(R < s.size()){
        if(S.size() <= n){
            if(mx < R - L) mx = R - L;
            char tmp = s[R];
            alpha[tmp - 'a']++;
            S.insert(tmp);
            R++;
        }
        if(S.size() > n){
            while(1){
                char tmp = s[L];
                alpha[tmp - 'a']--;
                L++;
                if(alpha[tmp - 'a'] == 0){
                    S.erase(tmp);
                    break;
                }
            }
            if(mx < R - L) mx = R - L;
        }
    }
    if(mx < R - L) mx = R - L;
    cout << mx;
}
