#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int parent[100001];
int deep[100001];
vector<int> adj[100001];
bool visit[100001];
int table[17][100001];
//2^16 < 100000

void dfs(int x){
    visit[x] = true;
    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(visit[next]) continue;
        deep[next] = deep[x] + 1;
        parent[next] = x;
        dfs(next);
    }
}

int LCA(int x,int y){
    if(deep[x] > deep[y]) swap(x,y);
    //y�� �� ���� ����
    int tmp = deep[y] - deep[x];
    for(int i=16; i>=0; i--){
        if(tmp >= (1 << i)){
            tmp -= (1 << i);
            y = table[i][y];
        }
    }
    //���� ���� ����

    if(x == y) return x;

    for(int i=16; i>=0; i--){
        if(table[i][x] != table[i][y]){
            x = table[i][x];
            y = table[i][y];
        }
    }
    //������ �ٸ��� �߿� �ִ븦 ã��, �׷� �����Ŵ� �ٷ� LCA!
    x = table[0][x];
    y = table[0][y];
    return x;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visit,false,sizeof visit);
    parent[1] = 1;
    deep[1] = 0;
    dfs(1); //1�� ��Ʈ��
    //�θ� ����, ���� ���� �Ϸ�

    for(int i=1; i<=n; i++){
        table[0][i] = parent[i]; //2^0 = 1
    }
    for(int i=1; i<=16; i++){
        for(int j=1; j<=n; j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int x,y;
        cin >> x >> y;
        cout << LCA(x,y) << "\n";
    }
}
