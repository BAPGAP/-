#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

map<string,int> M;
string S[1000010];
int cnt = 1;
int parent[1000010];
bool hasnum[1000010];

vector<int> v[1000010];
set<pair<int, int>> LPR;

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a,int b){
    int x = Find(a);
    int y = Find(b);
    if(x == y) return;

    if(S[x].size() > S[y].size()) swap(x,y);
    parent[y] = x;
}

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0; i<=1000010; i++){
        parent[i] = i;
        hasnum[i] = false;
    }
    string s;
    cin >> s;
    int pos1 = 0;
    int pos2 = 0;
    string tmp1,tmp2;
    string cmp;
    while(pos1 < s.size() || pos2 < s.size()){
        if(s[pos2] == '!' || s[pos2] == '='){
            tmp1 = s.substr(pos1,pos2-pos1);
            cmp = s.substr(pos2,2);
            pos1 = pos2 + 2;
            pos2 = pos1;
        }
        else if(s[pos2] == '&' || pos2 == s.size()){
            tmp2 = s.substr(pos1,pos2-pos1);
            pos1 = pos2 + 2;
            pos2 = pos1;

            bool L = M.find(tmp1) == M.end();
            if(L){
                M[tmp1] = cnt++;
                S[cnt-1] = tmp1;
            }
            bool R = M.find(tmp2) == M.end();
            if(R){
                M[tmp2] = cnt++;
                S[cnt-1] = tmp2;
            }

            if(cmp == "=="){
                if(tmp1 == tmp2) continue;
                Union(M[tmp1],M[tmp2]);
            }
        }
        else pos2++;
    }

    //node = 1 ~ (cnt-1)
    for(int i=1; i<cnt; i++){
        int x = Find(i);
        v[x].push_back(i);
    }

    string answer = "";

    for(int i=1; i<cnt; i++){
        if(v[i].size() == 0) continue;

        int cnt = 0;

        for(int j=0; j<v[i].size(); j++){
            string tmp = S[v[i][j]];
            if('0' <= tmp[tmp.size()-1] && tmp[tmp.size()-1] <= '9') cnt++;

            if(v[i][j] != i){
                answer += S[v[i][j]] + "==" + S[i] + "&&";
            }
        }
        if(cnt > 1){ //같은 집합안에 숫자가 2개 이상있으면
            cout << "0!=0";
            return 0;
        }
        else if(cnt == 1) hasnum[i] = true;
    }

    pos1 = 0;
    pos2 = 0;

    while(pos1 < s.size() || pos2 < s.size()){
        if(s[pos2] == '!' || s[pos2] == '='){
            tmp1 = s.substr(pos1,pos2-pos1);
            cmp = s.substr(pos2,2);
            pos1 = pos2 + 2;
            pos2 = pos1;
        }
        else if(s[pos2] == '&' || pos2 == s.size()){
            tmp2 = s.substr(pos1,pos2-pos1);
            pos1 = pos2 + 2;
            pos2 = pos1;

            if(cmp == "!="){
                //각 string 의 조상
                int L = Find(M[tmp1]);
                int R = Find(M[tmp2]);

                //a==b && a!=b인 경우
                if(L == R){
                    cout << "0!=0";
                    return 0;
                }

                //동치관계중 숫자 != 숫자가 있으면
                if(hasnum[L] && hasnum[R]) continue;

                if(L > R) swap(L,R);
                if(LPR.find({L,R}) == LPR.end()){
                    answer += S[L] + "!=" + S[R] + "&&";
                    LPR.insert({L,R});
                }
            }
        }
        else pos2++;
    }
    if(answer.empty()) cout << "0==0"; //항상 참인경우
    else cout << answer.substr(0,answer.size()-2);
}
