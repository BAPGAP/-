#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

char pan[502][502];
vector<int> adj[1000000];
int B[502][502][4]; //BÀÇ node
int cnt;
int scc_cnt;
int num[1000000];
bool visit[1000000];
int scc[1000000];
stack<int> S;
int L_cnt;

int no(int x){
    if(x % 2 == 1) return x+1;
    else return x-1;
}

int dfs(int x){
    num[x] = cnt++;
    S.push(x);
    int parent = num[x];

    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(num[next] == 0) parent = min(parent,dfs(next));
        else if(!visit[next]) parent = min(parent,num[next]);
    }

    if(parent == num[x]){
        while(1){
            int tmp = S.top();
            S.pop();
            visit[tmp] = true;
            scc[tmp] = scc_cnt;
            if(tmp == x) break;
        }
        scc_cnt++;
    }
    return parent;
}


void solve(){
    for(int i=1; i<L_cnt; i++){
        vector<int>().swap(adj[i]);
    }
    cnt = 1;
    scc_cnt = 1;
    L_cnt = 1;
    memset(pan,'.',sizeof pan);
    memset(B,0,sizeof B);
    memset(visit,false,sizeof visit);
    memset(num,0,sizeof num);
    memset(scc,0,sizeof scc);

    int n,m;
    int b_cnt = 0;
    int w_cnt = 0;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> pan[i][j];
            if(pan[i][j] == 'B'){
                for(int k=0; k<4; k++){
                    B[i][j][k] = L_cnt++;
                }
                b_cnt++;
            }
            else if(pan[i][j] == 'W') w_cnt++;
        }
    }

    if(w_cnt != 2 * b_cnt){
        cout << "NO\n";
        return;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            bool isb[4];
            bool isw[4];
            int node[4];
            node[0] = B[i-1][j][1];
            node[1] = B[i+1][j][0];
            node[2] = B[i][j-1][3];
            node[3] = B[i][j+1][2];
            if(pan[i][j] == 'B'){
                isw[0] = (pan[i-1][j] == 'W'); //U
                isw[1] = (pan[i+1][j] == 'W'); //D
                isw[2] = (pan[i][j-1] == 'W'); //L
                isw[3] = (pan[i][j+1] == 'W'); //R

                for(int k=0; k<4; k+=2){
                    if(isw[k] && isw[k+1]){}
                    else if(isw[k]){
                        adj[B[i][j][k+1]].push_back(B[i][j][k]);
                    }
                    else if(isw[k+1]){
                        adj[B[i][j][k]].push_back(B[i][j][k+1]);
                    }
                    else{
                        cout << "NO\n";
                        return;
                    }
                }
            }
            else if(pan[i][j] == 'W'){
                isb[0] = (pan[i-1][j] == 'B'); //U
                isb[1] = (pan[i+1][j] == 'B'); //D
                isb[2] = (pan[i][j-1] == 'B'); //L
                isb[3] = (pan[i][j+1] == 'B'); //R

                for(int k=0; k<4; k++){
                    for(int l=k+1; l<4; l++){
                        if(isb[k] && isb[l]){
                            adj[node[k]].push_back(no(node[l]));
                            adj[node[l]].push_back(no(node[k]));
                        }
                    }
                }
            }
        }
    }

    for(int i=1; i<L_cnt; i++){
        if(num[i] == 0) dfs(i);
    }
    bool ok = true;
    for(int i=1; i<L_cnt; i+=2){
        if(scc[i] == scc[i+1]){
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";

    return;
}

int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        solve();
    }
}
