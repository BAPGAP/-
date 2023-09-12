#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> adj[10001];
bool visit[10001] = {0};
int num[10001] = {0};
int cnt = 1;
int scc_cnt = 1;
int scc[10001];
stack<int> s;
char Answer[5001];

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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y,z;
        int n_x,n_y,n_z;
        char a,b,c;
        cin >> x >> a >> y >> b >> z >> c;
        if(a == 'B'){
            n_x = 2*x;
            x = x*2-1;
        }
        else{
            n_x = 2*x-1;
            x = 2*x;
        }
        if(b == 'B'){
            n_y = 2*y;
            y = y*2-1;
        }
        else{
            n_y = 2*y-1;
            y = 2*y;
        }
        if(c == 'B'){
            n_z = 2*z;
            z = z*2-1;
        }
        else{
            n_z = 2*z-1;
            z = 2*z;
        }
        adj[n_x].push_back(y);
        adj[n_x].push_back(z);
        adj[n_y].push_back(x);
        adj[n_y].push_back(z);
        adj[n_z].push_back(x);
        adj[n_z].push_back(y);
    }

    for(int i=1; i<=2*n; i++){
        if(num[i] == 0) dfs(i);
    }

    bool ok = true;
    for(int i=1; i<=n; i+=2){
        if(scc[i] == scc[i+1]){
            ok = false;
            break;
        }
    }
    if(ok){
        vector<pair<int,int>> vp; //속한 scc 번호순으로 정렬 , scc의 번호가 클수록 위상정렬상 앞에 있음 -> 따라서 큰거 부터 확인
        vp.push_back({-1,0});
        for(int i=1; i<=2*n; i++){
            vp.push_back({scc[i],i});
        }
        sort(vp.begin(),vp.end());
        memset(Answer,'n',sizeof Answer);
        for(int i=2*n; i>=1; i--){
            int node = vp[i].second;
            int real_node = (node+1)/2;
            if(Answer[real_node] == 'n'){ //아직 설정 안했으면
                if(node % 2 == 0) Answer[real_node] = 'B';
                else Answer[real_node] = 'R';
            }
        }
        for(int i=1; i<=n; i++){
            cout << Answer[i];
        }
        cout << "\n";
    }
    else cout << "-1";
}
