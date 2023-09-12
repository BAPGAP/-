#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> adj[10001];
bool finish[10001];
int num[10001] = {0}; //num[x] = 0 이면 방문한적이 없는거임
int cnt = 1;
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x){
    num[x] = cnt++; //임의의 번호를 부여
    s.push(x);
    int parent = num[x]; //일단 부모는 자기자신...이 가지고 있는  번호
    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(num[next] == 0) parent = min(parent,dfs(next));
        else if(!finish[next]){ //처리중인데 num != 0 이다, 즉 사이클이 생겼다
            parent = min(parent,num[next]); //더이상 dfs할 필요없음
        }
    }

    if(parent == num[x]){ //자신이 사이클의 부모인경우
        vector<int> scc;
        while(1){
            int tmp = s.top();
            s.pop();
            scc.push_back(tmp);
            finish[tmp] = true;
            if(tmp == x) break;
        }
        sort(scc.begin(),scc.end());
        SCC.push_back(scc);
    }
    return parent;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int v,e;
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y); //x -> y
    }
    memset(finish,false,sizeof finish);
    for(int i=1; i<=v; i++){
        if(num[i] == 0) dfs(i);
    }
    sort(SCC.begin(),SCC.end());
    cout << SCC.size() << "\n";
    for(int i=0; i<SCC.size(); i++){
        for(int j=0; j<SCC[i].size(); j++){
            cout << SCC[i][j] << " ";
        }
        cout << "-1\n";
    }
}
