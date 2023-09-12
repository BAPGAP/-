#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int dim[501]; //들어오는 간선 개수
int plu[501];
vector<pair<int,int>> v;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n;
        cin >> n;
        int cnt = 0;
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            dim[x] = cnt;
            cnt++;
            plu[i] = 0;
        }
        int m;
        cin >> m;
        for(int i=0; i<m; i++){
            int u,v;
            cin >> u >> v;
            if(dim[u] > dim[v]) swap(u,v);
            plu[u] += 1;
            plu[v] -= 1;
        }
        for(int i=1; i<=n; i++){
            dim[i] += plu[i];
            v.push_back({dim[i],i});
        }
        sort(v.begin(),v.end());
        bool ok = true;
        for(int i=1; i<n; i++){
            if(v[i].first == v[i-1].first){
                ok = false;
                break;
            }
        }
        if(ok){
            for(int i=0; i<n; i++){
                cout << v[i].second << " ";
            }
            cout << "\n";
        }
        else cout << "IMPOSSIBLE\n";
        vector<pair<int,int>>().swap(v);
    }
}
