#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> two;
long long t = 1;
int mn;

void solve(string x,string y){
    int cnt = 0;
    int pos = 0;
    for(int i=0; i<x.size(); i++){
        if(y[pos] == x[i]){
            cnt++;
            pos++;
            if(pos == y.size()) break;
        }
    }

    int gap = x.size() - cnt + y.size() - cnt;
    if(gap < mn) mn = gap;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;

    while(t <= 4611686018427387903){
        string tmp = to_string(t);
        two.push_back(tmp);
        t *= 2;
    }

    while(T--){
        string s;
        cin >> s;
        mn = 987654321;
        for(int i=0; i<two.size(); i++){
            solve(s,two[i]);
        }
        cout << mn << "\n";
    }
}
