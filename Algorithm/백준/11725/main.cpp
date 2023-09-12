#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];

int P[100001];
int visit[100001] = {0};

void dfs(int x){
    visit[x] = 1;
    for(int i=0; i<v[x].size(); i++){
        int next = v[x][i];
        if(visit[next] == 0){
            P[next] = x;
            dfs(next);
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int x,y;
    for(int i=1; i<n; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);

    for(int i=2; i<=n; i++){
        cout << P[i] << "\n";
    }
    return 0;
}
