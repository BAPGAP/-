#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

string s;
string w;
vector<string> vs[12];
int ca[101][101];

int check(int x,int y){

    int& ret = ca[x][y];
    if(ret != -1) return ret;

    while(x < s.size() && y < w.size() && (w[x] == '?' || w[x] == s[y])){
        x++;
        y++;
    }
    if(x == w.size()) return ret = (x == s.size());

    if(w[x] == '*'){
        for(int i=y; i<=s.size(); i++){
            if(check(x+1,i)){
                return ret = 1;
            }
        }
    }
    return ret = 0;
}

int main()
{
    int T;
    int n;
    cin >> T;
    while(T--){

        cin >> w;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> s;
            memset(ca,-1,sizeof(ca));
            // s == w ??
            if(check(0,0)){
                vs[T].push_back(s);
            }
        }
        sort(vs[T].begin(),vs[T].end());
        for(int i=0; i<vs[T].size(); i++){
            cout << vs[T][i] << "\n";
        }
    }
}
