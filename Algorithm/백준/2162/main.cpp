#include <iostream>

using namespace std;

struct point{
    long double x,y;
};
struct line{
    point P1,P2;
};

line L[3001];

bool ccw(line A,line B){
    long double x1 = A.P1.x;
    long double y1 = A.P1.y;
    long double x2 = A.P2.x;
    long double y2 = A.P2.y;
    long double x3 = B.P1.x;
    long double y3 = B.P1.y;
    long double x4 = B.P2.x;
    long double y4 = B.P2.y;

    long double L1_1 = x1*y2+x2*y3+x3*y1 - y1*x2-y2*x3-y3*x1;
    long double L1_2 = x1*y2+x2*y4+x4*y1 - y1*x2-y2*x4-y4*x1;
    long double L2_1 = x3*y4+x4*y1+x1*y3 - y3*x4-y4*x1-y1*x3;
    long double L2_2 = x3*y4+x4*y2+x2*y3 - y3*x4-y4*x2-y2*x3;

    bool L1 = false;
    bool L2 = false;
    if(L1_1 <= 0 && L1_2 >= 0) L1 = true;
    else if(L1_1 >= 0 && L1_2 <= 0) L1 = true;
    if(L2_1 >= 0 && L2_2 <= 0) L2 = true;
    else if(L2_1 <= 0 && L2_2 >= 0) L2 = true;

    bool notuch = false;
    if(x1 < x3 && x2 < x3 && x1 < x4 && x2 < x4) notuch = true;
    else if(x1 > x3 && x2 > x3 && x1 > x4 && x2 > x4) notuch = true;
    else if(y1 < y3 && y2 < y3 && y1 < y4 && y2 < y4) notuch = true;
    else if(y1 > y3 && y2 > y3 && y1 > y4 && y2 > y4) notuch = true;

    //선분이 겹치지않고 기울기가 같을때
    if((y2-y1)*(x4-x3) == (y4-y3)*(x2-x1) && notuch) return false;
    else if(L1 && L2) return true;
    else return false;
}

int parent[3001];
int height[3001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a,int b){
    int x = Find(a);
    int y = Find(b);

    if(x == y) return;

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
    for(int i=1; i<=n; i++){
        cin >> L[i].P1.x >> L[i].P1.y >> L[i].P2.x >> L[i].P2.y;
        parent[i] = i;
        height[i] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(ccw(L[i],L[j])){
                Union(i,j);
            }
        }
    }
    int cnt[3001] = {0};
    for(int i=1; i<=n; i++){
        cnt[Find(i)]++;
    }
    int mx = 0;
    int group = 0;
    for(int i=1; i<=n; i++){
        if(cnt[i] > 0) group++;
        if(cnt[i] > mx) mx = cnt[i];
    }
    cout << group << "\n" << mx << "\n";
}
