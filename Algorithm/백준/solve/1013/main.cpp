#include <iostream>
#include <string>

using namespace std;

string s;

bool ok(string S,int x,int y){
    if(x == y) return false;
    if(x > y) return true;

    if(S[y] == '0') return false;
    if(S[x] == S[x+1]) return false;

    if(S[x] == '0' && S[x+1] == '1') return ok(S,x+2,y);
    for(int i=x+1; i<y; i++){
         if(S[i-1] == '1' && S[i] == '0' && S[i+1] == '1') return ok(S,x,i-1) && ok(S,i+2,y);
    }

    for(int i=x+1; i<y; i++){
        if(S[i-1] == '0' && S[i] == '1' && S[i+1] == '0') return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(ok(s,0,s.size()-1)) cout << "YES\n";
        else cout << "NO\n";
    }
}
