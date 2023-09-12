#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int adj[101];
int visit[101]; // 1 : �湮�Ϸ�,    0 : �湮��,    -1 : ���� �湮����
vector<int> v;

void dfs(int x){
    visit[x] = 0;
    int next = adj[x];
    if(visit[next] == 0){
        //next���� x���� cycle�� ����
        for(int i=next; ; i=adj[i]){
            v.push_back(i);
            if(i == x) break;
        }
    }
    else if(visit[next] == -1) dfs(next);
    visit[x] = 1;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        adj[i] = x;
    }
    memset(visit,-1,sizeof visit);
    for(int i=1; i<=n; i++){
        if(visit[i] == -1){
            dfs(i);
        }
    }
    sort(v.begin(),v.end());
    cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
}
