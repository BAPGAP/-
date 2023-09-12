#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int cnt[10000] = {0};
int sum;
string s;
int n;
void dfs(vector<vector<int>> v,int pos){
    if(pos == n){
        cout << sum << "\n";
        cnt[sum]++;
        return;
    }
    int tmp = s[pos] - '0';
    for(int i=0; i<7; i++){
        if(i == 6){
            dfs(v,pos+1);
            break;
        }
        sum = sum*10 + v[tmp][i];
        dfs(v,pos+1);
        sum = (sum - v[tmp][i])/10;
    }
}

int solution(vector<vector<int>> dice) {
    n = dice.size();
    if(n == 1) s = "0";
    if(n == 2) s = "01";
    if(n == 3) s = "012";
    if(n == 4) s = "0123";
    sum = 0;
    dfs(dice,0);
    while(next_permutation(s.begin(), s.end())){
        sum = 0;
        dfs(dice,0);
    }

    for(int i=1; i<40; i++){
        if(cnt[i] == 0) return i;
    }
}

int main(){
    vector<vector<int>> vp;
    vector<int> v(6);
    for(int i=0; i<3; i++){
        for(int j=0; j<6; j++){
            cin >> v[j];
        }
        vp.push_back(v);
    }
    solution(vp);
}
