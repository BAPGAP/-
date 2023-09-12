#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

char c[102][102];
int node[102][102][4]; //c[i][j]의 k방향 노드
vector<int> adj[20001];
int r,s;
int cnt = 1;
int scc_cnt = 1;
int num[20001] = {0};
bool visit[20001] = {0};
int scc[20001];
stack<int> S;
int Answer[20001]; //1 T, 0 F

int no(int x){
    if(x%2 == 1) return x+1;
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


int way(int x,int y,int d){
    if(d == 0){
        for(int i=x-1; i>=0; i--){
            if(c[i][y] == 'T') return node[i][y][1];
            if(c[i][y] == '#') return 0;
        }
        return 0;
    }
    else if(d == 1){
        for(int i=x+1; i<=r; i++){
            if(c[i][y] == 'T') return node[i][y][0];
            if(c[i][y] == '#') return 0;
        }
        return 0;
    }
    else if(d == 2){
        for(int i=y-1; i>=0; i--){
            if(c[x][i] == 'T') return node[x][i][3];
            if(c[x][i] == '#') return 0;
        }
        return 0;
    }
    else if(d == 3){
        for(int i=y+1; i<=s; i++){
            if(c[x][i] == 'T') return node[x][i][2];
            if(c[x][i] == '#') return 0;
        }
        return 0;
    }
}

int main()
{
    memset(c,'.',sizeof c);
    int T_cnt = 1;
    cin >> r >> s;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=s; j++){
            cin >> c[i][j];
            if(c[i][j] == 'T'){
                for(int k=0; k<4; k++){
                    node[i][j][k] = T_cnt++;
                }
            }
        }
    }
    for(int i=1; i<=r; i++){
        for(int j=1; j<=s; j++){
            if(c[i][j] == 'n'){
                int U,D,L,R;
                U = way(i,j,0);
                D = way(i,j,1);
                L = way(i,j,2);
                R = way(i,j,3);
                int dir[4] = {U,D,L,R};

                if(U > 0 && D > 0){
                    adj[U].push_back(no(U));
                    adj[D].push_back(no(D));
                    if(L > 0){
                        adj[no(L)].push_back(L);
                    }
                    else{
                        adj[no(R)].push_back(R);
                    }
                }
                else if(L > 0 && R > 0){
                    adj[L].push_back(no(L));
                    adj[R].push_back(no(R));
                    if(U > 0){
                        adj[no(U)].push_back(U);
                    }
                    else{
                        adj[no(D)].push_back(D);
                    }
                }
                else if(U == 0 && D == 0){
                    if(L > 0){
                        adj[no(L)].push_back(L);
                    }
                    else{
                        adj[no(R)].push_back(R);
                    }
                }
                else if(L == 0 && R == 0){
                    if(U > 0){
                        adj[no(U)].push_back(U);
                    }
                    else{
                        adj[no(D)].push_back(D);
                    }
                }
                else{
                    for(int k=0; k<4; k++){
                        for(int l=k+1; l<4; l++){
                            if(dir[k] > 0 && dir[l] > 0){
                                adj[no(dir[k])].push_back(dir[l]);
                                adj[no(dir[l])].push_back(dir[k]);
                            }
                        }
                    }
                }
            }
            else if(c[i][j] == 'T'){
                int U,D,L,R;
                U = way(i,j,0);
                D = way(i,j,1);
                L = way(i,j,2);
                R = way(i,j,3);
                int dir[4] = {U,D,L,R};
                if(U > 0) adj[U].push_back(no(U));
                if(D > 0) adj[D].push_back(no(D));
                if(L > 0) adj[L].push_back(no(L));
                if(R > 0) adj[R].push_back(no(R));
            }
        }
    }

    for(int i=1; i<T_cnt; i++){
        if(adj[i].size() > 0 && num[i] == 0) dfs(i);
    }
    vector<pair<int,int>> tmp;
    tmp.push_back({-1,0});
    for(int i=1; i<T_cnt; i++){
        tmp.push_back({scc[i],i});
    }

    sort(tmp.begin(),tmp.end());
    memset(Answer,-1,sizeof Answer);
    for(int i=T_cnt-1; i>0; i--){
        int fake_node = tmp[i].second;
        int real_node = (fake_node + 1)/2;
        if(Answer[real_node] == -1){
            Answer[real_node] = 1 - fake_node%2;
        }
    }

    int T_num = 1;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=s; j++){
            if(c[i][j] != 'T') cout << c[i][j];
            else{
                if(Answer[T_num] == 1 && Answer[T_num+1] == 1) cout << "4";
                else if(Answer[T_num] == 1 && Answer[T_num+1] == 0) cout << "3";
                else if(Answer[T_num] == 0 && Answer[T_num+1] == 0) cout << "2";
                else if(Answer[T_num] == 0 && Answer[T_num+1] == 1) cout << "1";
                T_num += 2;
            }
        }
        cout << "\n";
    }
}
