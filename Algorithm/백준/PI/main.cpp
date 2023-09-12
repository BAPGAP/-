#include <iostream>
#include <cstring>

using namespace std;

int l[10001];
string s;

int score(int start,int len){
    start--;
    bool ok = true;
    for(int i=start; i<start+len-1; i++){
        if(s[i] != s[i+1]) ok = false;
    }
    if(ok) return 1;
    ok = true;
    for(int i=start; i<start+len-1; i++){
        int tmp = s[i] - s[i+1];
        if(tmp != 1) ok = false;
    }
    if(ok) return 2;
     ok = true;
    for(int i=start; i<start+len-1; i++){
        int tmp = s[i] - s[i+1];
        if(tmp != -1) ok = false;
    }
    if(ok) return 2;
    ok = true;
    for(int i=start; i<start+len; i++){
        if((i-start) % 2 == 0 && s[start] != s[i]) ok = false;
        if((i-start) % 2 == 1 && s[start+1] != s[i]) ok = false;
    }
    if(ok) return 4;

    ok = true;
    int diff = s[start+1] - s[start];
    for(int i=start+2; i<start+len; i++){
        int tmp = s[i] - s[i-1];
        if(tmp != diff) ok = false;
    }
    if(ok) return 5;

    return 10;
}

int gogo(int left){
    int& ret = l[left];
    if(ret != -1) return ret;

    ret = 987654321;

    for(int i=3; i<=5; i++){
        if(left >= i) ret = min(ret,gogo(left-i) + score(left-i+1,i));
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        memset(l,-1,sizeof(l));
        cin >> s;
        int n = s.size();
        l[2] = 987654321;
        l[1] = 987654321;
        l[0] = 0;

        cout << gogo(n) << "\n";
    }
}
