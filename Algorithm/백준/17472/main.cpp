#include <iostream>
#include <algorithm>

using namespace std;

int a[12][12] = {0};
int cnt = 2;
int parent[10];
int height[10];

void make_island(int x,int y){
    a[x][y] = cnt;
    if(a[x-1][y] == 1) make_island(x-1,y);
    if(a[x+1][y] == 1) make_island(x+1,y);
    if(a[x][y-1] == 1) make_island(x,y-1);
    if(a[x][y+1] == 1) make_island(x,y+1);
}

struct dis_node{
    int dis;
    int node1;
    int node2;
};

dis_node D[300];

bool compare(dis_node A,dis_node B){
    return A.dis < B.dis;
}

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x,int y){
    if(height[x] > height[y]) swap(x,y);
    parent[x] = y;
    if(height[x] == height[y]) height[y]++;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    } //지도 받음
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == 1){
                make_island(i,j);
                cnt++;
            }
        }
    }
    //현재 섬은 [2, cnt) 의 노드를 가짐

    for(int i=2; i<cnt; i++){
        parent[i] = i;
        height[i] = 1;
    }
    int tmp = 0;

    for(int i=1; i<=n; i++){ //가로 다리
        int pos1=11,pos2=0;
        for(int j=2; j<=m; j++){
            if(a[i][j-1] != a[i][j] && a[i][j-1] != 0) pos1 = j-1;
            else if(a[i][j-1] != a[i][j] && a[i][j-1] == 0){
                pos2 = j;
                if(pos1 < pos2){
                    D[tmp].dis = pos2 - pos1 - 1;
                    D[tmp].node1 = a[i][pos1];
                    D[tmp].node2 = a[i][pos2];
                    tmp++;
                }
            }
        }
    }
    for(int j=1; j<=m; j++){ //세로 다리
        int pos1=11,pos2=0;
        for(int i=2; i<=n; i++){
            if(a[i-1][j] != a[i][j] && a[i-1][j] != 0) pos1 = i-1;
            else if(a[i-1][j] != a[i][j] && a[i-1][j] == 0){
                pos2 = i;
                if(pos1 < pos2){
                    D[tmp].dis = pos2 - pos1 - 1;
                    D[tmp].node1 = a[pos1][j];
                    D[tmp].node2 = a[pos2][j];
                    tmp++;
                }
            }
        }
    }
    sort(D,D+tmp,compare);

    int Answer = 0;

    for(int i=0; i<tmp; i++){
        if(D[i].dis == 1) continue;
        int p1 = Find(D[i].node1);
        int p2 = Find(D[i].node2);
        if(p1 == p2) continue;
        Union(p1,p2);
        Answer += D[i].dis;
    }

    bool isok = true;

    for(int i=3; i<cnt; i++){
        if(Find(i-1) != Find(i)){
            isok = false;
            break;
        }
    }

    if(isok) cout << Answer;
    else cout << "-1";


    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for(int i=0; i<tmp; i++){
        cout << D[i].dis << " " << D[i].node1 << " " << D[i].node2 << "\n";
    }
    */

}
