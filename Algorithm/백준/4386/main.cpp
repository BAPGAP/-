#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double x[101];
double y[101];

struct dis_node{
    double dis;
    int node1,node2;
};

bool compare(dis_node A,dis_node B){
    return A.dis < B.dis;
}

int parent[101];
int height[101];

double Answer = 0;

double gap(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
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
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
        parent[i] = i;
        height[i] = 1;
    }

    dis_node D[6000];
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            D[cnt].dis = gap(x[i],y[i],x[j],y[j]);
            D[cnt].node1 = i;
            D[cnt].node2 = j;
            cnt++;
        }
    }
    sort(D,D+cnt,compare);
    for(int i=0; i<cnt; i++){
        int p1 = Find(D[i].node1);
        int p2 = Find(D[i].node2);
        if(p1 == p2) continue;
        Answer += D[i].dis;
        Union(p1,p2);
    }
    cout << Answer;
}
