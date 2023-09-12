#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> bang[100001]; //현재상태, 스위치1,스위치 2
vector<int> adj[200001];
int num[200001] = {0};
bool visit[200001] = {0};
int cnt = 1;
int scc_cnt = 1;
stack<int> s;
int scc[200001];

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
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        bang[i].push_back(x);
    }
    for(int i=1; i<=m; i++){ //i번 스위치와 연결된 방정보
        int k;
        cin >> k; //방개수
        for(int j=0; j<k; j++){
            int x;
            cin >> x; //x번 방은 i번 스위치와 연결되어 있다
            bang[x].push_back(i);
        }
    }
    for(int i=1; i<=n; i++){
        int tmp1 = bang[i][1];
        int tmp2 = bang[i][2];
        if(bang[i][0] == 0){
            adj[tmp1*2-1].push_back(2*tmp2);
            adj[tmp2*2-1].push_back(2*tmp1);
            adj[tmp1*2].push_back(2*tmp2-1);
            adj[tmp2*2].push_back(2*tmp1-1);
        }
        else{
            adj[tmp1*2-1].push_back(2*tmp2-1);
            adj[tmp2*2-1].push_back(2*tmp1-1);
        }
    }
    for(int i=1; i<=2*m; i++){
        if(num[i] == 0) dfs(i);
    }
    bool ok = true;
    for(int i=1; i<=2*m; i+=2){
        if(scc[i] == scc[i+1]){
            ok = false;
            break;
        }
    }
    if(ok) cout << "1";
    else cout << "0";
}
