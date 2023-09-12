#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> adj[400001];
vector<int> F[400001];
vector<pair<int,int>> P; //(limit val, node);

int num[400001] = {0};
bool visit[400001] = {0};
int cnt = 1;
int scc_cnt = 1;
stack<int> s;
int scc[400001];

int no(int x){
    if(x % 2 == 1) return x+1;
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
    int n;
    cin >> n;
    int L = 0,R = 0;
    for(int i=1; i<=n; i++){
        int f1,f2,l1,l2;
        cin >> f1 >> l1 >> f2 >> l2;
        if(min(l1,l2) > L) L = min(l1,l2);
        if(max(l1,l2) > R) R = max(l1,l2);
        F[f1].push_back(2*i-1);
        if(F[f1].size() == 2){
            adj[F[f1][0]].push_back(no(F[f1][1]));
            adj[F[f1][1]].push_back(no(F[f1][0]));
        }
        F[f2].push_back(2*i);
        if(F[f2].size() == 2){
            adj[F[f2][0]].push_back(no(F[f2][1]));
            adj[F[f2][1]].push_back(no(F[f2][0]));
        }
        //P.push_back({l1,2*i-1});
        //P.push_back({l2,2*i});
    }
    //�Ӱ谪 L <=  <= R
    for(int i=1; i<=2*n; i++){
        if(num[i] == 0) dfs(i);
    }
    for(int i=1; i<=2*n; i+=2){
        if(scc[i] == scc[i+1]){
            cout << "-1";
            return 0;
        }
    }
    sort(P.begin(),P.end());
    while(L < R){




    }
}
