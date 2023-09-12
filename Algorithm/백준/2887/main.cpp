#include <iostream>
#include <algorithm>

using namespace std;

struct point{
    int x,y,z;
    int node;
};
struct dis_node{
    int dis,node1,node2;
};

point P[100001];

bool compare_x(point A,point B){
    return A.x < B.x;
}
bool compare_y(point A,point B){
    return A.y < B.y;
}
bool compare_z(point A,point B){
    return A.z < B.z;
}
bool compare(dis_node A,dis_node B){
    return A.dis < B.dis;
}

int parent[100001];
int height[100001];

dis_node D[300000];

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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> P[i].x >> P[i].y >> P[i].z;
        P[i].node = i;
        parent[i] = i;
        height[i] = 1;
    }
    int cnt = 0;
    sort(P,P+n,compare_x);
    for(int i=1; i<n; i++){
        D[cnt].dis = P[i].x - P[i-1].x;
        D[cnt].node1 = P[i].node;
        D[cnt].node2 = P[i-1].node;
        cnt++;
    }
    sort(P,P+n,compare_y);
    for(int i=1; i<n; i++){
        D[cnt].dis = P[i].y - P[i-1].y;
        D[cnt].node1 = P[i].node;
        D[cnt].node2 = P[i-1].node;
        cnt++;
    }
    sort(P,P+n,compare_z);
    for(int i=1; i<n; i++){
        D[cnt].dis = P[i].z - P[i-1].z;
        D[cnt].node1 = P[i].node;
        D[cnt].node2 = P[i-1].node;
        cnt++;
    }

    sort(D,D+cnt,compare);

    int Answer = 0;

    for(int i=0; i<cnt; i++){
        int p1 = Find(D[i].node1);
        int p2 = Find(D[i].node2);
        if(p1 == p2) continue;
        Union(p1,p2);
        Answer += D[i].dis;
    }
    cout << Answer;
}
