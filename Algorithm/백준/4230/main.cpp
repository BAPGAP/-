#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

int num[61];
bool visit[61];
vector<int> adj[61];
stack<int> s;
int cnt;
int scc_cnt;
int scc[61];
int Answer[31];
vector<pair<int,int>> vp;
string s1,s2;
int n1,n2;

int no(int x){
    if(x%2 == 1) return x+1;
    else return x-1;
}

int dfs(int x){
    num[x] = cnt++;
    s.push(x);
    int parent = num[x];

    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(num[next] == 0) parent = min(parent,dfs(next));
        else if(!visit[next]) parent = min(parent,num[next]);
    }

    if(parent == num[x]){
        while(1){
            int tmp = s.top();
            s.pop();
            visit[tmp] = true;
            scc[tmp] = scc_cnt;
            if(tmp == x) break;
        }
        scc_cnt++;
    }
    return parent;
}

int main()
{
    int n,m;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        memset(num,0,sizeof num);
        memset(visit,false,sizeof visit);
        cnt = 1;
        scc_cnt = 1;

        for(int i=0; i<m; i++){
            cin >> s1 >> s2;
            if(s1.size() == 2){
                if(s1[1] == 'h') n1 = 2 * (s1[0] - '0') + 1;
                else n1 = 2 * (s1[0] - '0') + 2;
            }
            else{
                if(s1[2] == 'h') n1 = 2 * ((s1[0] - '0') * 10 + (s1[1] - '0')) + 1;
                else n1 = 2 * ((s1[0] - '0') * 10 + (s1[1] - '0')) + 2;
            }
            if(s2.size() == 2){
                if(s2[1] == 'h') n2 = 2 * (s2[0] - '0') + 1;
                else n2 = 2 * (s2[0] - '0') + 2;
            }
            else{
                if(s2[2] == 'h') n2 = 2 * ((s2[0] - '0') * 10 + (s2[1] - '0')) + 1;
                else n2 = 2 * ((s2[0] - '0') * 10 + (s2[1] - '0')) + 2;
            }
            adj[n1].push_back(no(n2));
            adj[n2].push_back(no(n1));
        }
        adj[2].push_back(1);

        for(int i=1; i<=2*n; i++){
            if(num[i] == 0) dfs(i);
        }

        bool ok = true;
        for(int i=1; i<=2*n; i+=2){
            if(scc[i] == scc[i+1]){
                ok = false;
                break;
            }
        }
        if(ok){
            vector<pair<int,int>>().swap(vp);
            memset(Answer,-1,sizeof Answer);
            vp.push_back({-1,0});
            for(int i=1; i<=2*n; i++){
                vp.push_back({scc[i],i});
            }
            sort(vp.begin(),vp.end());

            for(int i=vp.size()-1; i>0; i--){
                int fake_node = vp[i].second;
                int real_node = (fake_node-1)/2;
                if(Answer[real_node] == -1){
                    Answer[real_node] = 1 - fake_node%2;
                }
            }
            for(int i=1; i<n; i++){
                cout << i;
                if(Answer[i] == 1) cout << "w ";
                else cout << "h ";
            }
            cout << "\n";
        }
        else cout << "bad luck\n";

        for(int i=1; i<=2*n; i++){
            vector<int>().swap(adj[i]);
        }
    }
}
