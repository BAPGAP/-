#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string,int> M;
string change[200001];
vector<int> adj[200001];
bool visit[200001] = {0};
vector<string> vs;

void dfs(int x){
    visit[x] = true;
    vs.push_back(change[x]);
    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(!visit[next]) dfs(next);
    }
}

int main()
{
    M["Baba"] = 1;
    change[1] = "Baba";
    int n;
    int cnt = 2;
    cin >> n;
    for(int i=0; i<n; i++){
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        int p,q;
        if(M.find(s1) == M.end()){
            p = cnt;
            change[cnt] = s1;
            M[s1] = cnt++;
        }
        else p = M[s1];
        if(M.find(s3) == M.end()){
            q = cnt;
            change[cnt] = s3;
            M[s3] = cnt++;
        }
        else q = M[s3];
        //p -> q
        adj[p].push_back(q);
    }
    dfs(1);
    sort(vs.begin(),vs.end());
    for(int i=0; i<vs.size(); i++){
        if(vs[i] != "Baba") cout << vs[i] << "\n";
    }
}
