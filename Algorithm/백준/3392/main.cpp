#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct point{
    ll x1,y1,x2,y2;
};

point P[10001];
vector<vector<ll>> v;
ll tree[120004] = {0};
ll cnt[120004] = {0};

void update(int node,int L,int R,int l,int r,ll gap){
    if(r < L || R < l) return;
    else if(l <= L && R <= r) cnt[node] += gap; //어차피 같은 구간 더하고 빼는 연산 반복이므로 굳이 게으른 '전파'할 필요 없음!
    else{
        int M = (L+R)/2;
        update(2*node,L,M,l,r,gap);
        update(2*node+1,M+1,R,l,r,gap);
    }
    tree[node] = 0;
    if(cnt[node] > 0) tree[node] = R - L + 1;
    if(cnt[node] == 0 && L < R) tree[node] = tree[node*2] + tree[node*2+1];
}

int main()
{
    int n;
    cin >> n;
    ll x1,y1,x2,y2;
    for(int i=0; i<n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back(vector<ll>{x1,1,y1,y2}); //open
        v.push_back(vector<ll>{x2,-1,y1,y2}); //close
    }
    sort(v.begin(),v.end());

    ll Answer = 0;

    update(1,0,29999,v[0][2],v[0][3]-1,1);
    ll line = v[0][0];

    for(int i=1; i<v.size(); i++){
        ll tmp = v[i][0];
        Answer += (tmp - line) * tree[1];
        update(1,0,29999,v[i][2],v[i][3]-1,v[i][1]);
        line = tmp;
    }
    cout << Answer;
}

/*
4
5 6 12 11
7 1 15 5
10 4 18 8
19 1 23 11
*/
