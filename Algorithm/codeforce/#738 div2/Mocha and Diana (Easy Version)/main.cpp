#include <iostream>
#include <vector>

using namespace std;

int p[2][3001];
vector<pair<int,int>> vp;

int Find(int x,int t){
    if(x == p[t][x]) return x;
    return p[t][x] = Find(p[t][x],t);
}

void Union(int x,int y,int t){
    p[t][x] = y;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m1,m2;
    cin >> n >> m1 >> m2;

    for(int i=1; i<=n; i++){
        p[0][i] = i;
        p[1][i] = i;
    }
    for(int i=0; i<m1; i++){
        int x,y;
        cin >> x >> y;
        Union(Find(x,0),Find(y,0),0);
    }
    for(int i=0; i<m2; i++){
        int x,y;
        cin >> x >> y;
        Union(Find(x,1),Find(y,1),1);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int tmp[4];
            tmp[0] = Find(i,0);
            tmp[1] = Find(j,0);
            if(tmp[0] == tmp[1]) continue;
            tmp[2] = Find(i,1);
            tmp[3] = Find(j,1);
            if(tmp[2] == tmp[3]) continue;

            cnt++;
            vp.push_back({i,j});
            Union(tmp[0],tmp[1],0);
            Union(tmp[2],tmp[3],1);
        }
    }
    cout << cnt << "\n";
    for(int i=0; i<vp.size(); i++){
        cout << vp[i].first << " " << vp[i].second << "\n";
    }
}
