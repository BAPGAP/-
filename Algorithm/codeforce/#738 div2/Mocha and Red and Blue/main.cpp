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
        string s1,s2;
        s1.resize(n);
        s2.resize(n);
        int cnt1=0;
        int cnt2=0;
        if(s[0] == '?'){
            s1[0] = 'R';
            s2[0] = 'B';
        }
        else{
            s1[0] = s[0];
            s2[0] = s[0];
        }
        for(int i=1; i<n; i++){
            if(s[i] == '?' && s1[i-1] == 'B') s1[i] = 'R';
            else if(s[i] == '?' && s1[i-1] == 'R') s1[i] = 'B';
            if(s[i] == '?' && s2[i-1] == 'B') s2[i] = 'R';
            else if(s[i] == '?' && s2[i-1] == 'R') s2[i] = 'B';

            if(s[i] != '?'){
                s1[i] = s[i];
                s2[i] = s[i];
            }

            if(s1[i] == s1[i-1]) cnt1++;
            if(s2[i] == s2[i-1]) cnt2++;
        }

        if(cnt1 > cnt2) cout << s2 << "\n";
        else cout << s1 << "\n";
    }
}
