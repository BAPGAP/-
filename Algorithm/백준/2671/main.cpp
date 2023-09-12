#include <iostream>

using namespace std;

string s;

bool check(string s,int l,int r){
    if(l > r) return true;
    if(l == r) return false;
    if(s[r] == '0') return false;
    if(s[l] == '0' && s[l+1] == '0') return false;
    if(s[l] == '0' && s[l+1] == '1') return check(s,l+2,r);
    int pos;
    for(int i=l+1; i<=r; i++){
        if(s[i] == '1'){
            pos = i;
            break;
        }
    }
    if(l+1 == pos || l+2 == pos) return false;
    if(pos == r) return true;
    int pos2;
    for(int i=pos; i<=r; i++){
        if(s[i] == '1') pos2 = i;
        else break;
    }
    if(pos == pos2) return check(s,pos2+1,r);
    else return check(s,pos2+1,r) || check(s,pos2,r);
}

int main()
{
    cin >> s;
    if(check(s,0,s.size()-1)) cout << "SUBMARINE";
    else cout << "NOISE";
}
