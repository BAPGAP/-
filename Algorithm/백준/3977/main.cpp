#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> adj[100001];
int Answer;
int num[100001];
bool visit[100001];
int cnt;
stack<int> s;
int a[100001]; //��� scc�� ���ϴ���?
int scc;
int in[100001]; //scc ���� ������� �߿����� ������ ��������

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
            a[tmp] = scc;
            if(tmp == x) break;
        }
        scc++;
    }
    return parent;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n,m;
        cin >> n >> m;
        for(int i=0; i<m; i++){
            int u,v;
            cin >> u >> v;
            adj[u+1].push_back(v+1);
        }
        memset(num,0,sizeof num);
        memset(visit,false,sizeof visit);
        cnt = 1;
        scc = 1;
        for(int i=1; i<=n; i++){
            if(num[i] == 0) dfs(i);
        }

        memset(in,0,sizeof in);

        for(int i=1; i<=n; i++){
            for(int j=0; j<adj[i].size(); j++){
                int next = adj[i][j];
                if(a[i] != a[next]){ //i -> next�ε� ���� �����ִ� scc�� �ٸ��ٸ�
                    in[a[next]]++;
                }
            }
        }

        int Answer = 0;
        int pos;
        for(int i=1; i<scc; i++){
            if(in[i] == 0){
                Answer++;
                pos = i;
            }
        }
        if(Answer > 1) cout << "Confused\n\n";
        else{
            vector<int> P;
            for(int i=1; i<=n; i++){
                if(a[i] == pos) P.push_back(i);
            }
            sort(P.begin(),P.end());
            for(int i=0; i<P.size(); i++){
                cout << P[i] - 1 << "\n";
            }
            cout << "\n";
        }

        for(int i=1; i<=n; i++){
            vector<int>().swap(adj[i]);
        }
    }
}
