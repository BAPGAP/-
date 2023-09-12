#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double xandy[1000][2]; //0:x 1:y
struct dis_node{
    double dis;
    int node1,node2;
};

dis_node D[500000];

bool compare(dis_node A,dis_node B){
    return  A.dis < B.dis;
}

double gap(double x1,double y1,double x2,double y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int parent[1000];
int height[1000];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int a,int b){
    int x = Find(a);
    int y = Find(b);
    if(x == y) return false;

    if(height[x] > height[y]) swap(x,y);
    parent[x] = y;
    if(height[x] == height[y]) height[y]++;
    return true;
}


int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> xandy[i][0] >> xandy[i][1];
        parent[i] = i;
        height[i] = 1;
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            D[cnt].dis = gap(xandy[i][0],xandy[i][1],xandy[j][0],xandy[j][1]);
            D[cnt].node1 = i;
            D[cnt].node2 = j;
            cnt++;
        }
    }
    sort(D,D+cnt,compare);

    int x,y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        Union(x-1,y-1);
    }

    double Answer = 0;

    for(int i=0; i<cnt; i++){
        if(Union(D[i].node1,D[i].node2)) Answer += D[i].dis;
    }
    cout << fixed;
    cout.precision(2);
    cout << Answer;
}
