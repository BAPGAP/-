#include <iostream>
#include <vector>

using namespace std;

vector<int> v[501];
int visit[501];
int degree;
int node;

void dfs(int x){
    visit[x] = 1;
    degree += v[x].size();
    node++;

    for(int i=0; i<v[x].size(); i++){
        int next = v[x][i];
        if(visit[next] == 0){
            dfs(next);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    for(int tc = 1; ; tc++){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        int x,y,T;
        T = 0;
        for(int i=0; i<m; i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int i=1; i<=n; i++){
            visit[i] = 0;
        }
        for(int i=1; i<=n; i++){
            if(visit[i] == 0){
                degree = 0;
                node = 0;
                dfs(i);
                if(degree < 2 * node) T++;
                //cout << "tc:" << tc << " i:" << i << " node:" << node << " degree: " << degree << "\n";
            }
        }
        cout << "Case " << tc << ": ";
        if(T == 0) cout << "No trees.\n";
        else if(T == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << T << " trees.\n";
        for(int i=1; i<=n; i++){
            vector<int>().swap(v[i]);
        }
    }
}
