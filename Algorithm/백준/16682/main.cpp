#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll tree[400100][8]={0};
ll cnt[400100][8]={0};
ll sum[8] = {0};

vector<ll> edit_y;
vector<vector<ll>> v;

ll press(ll y){
    return lower_bound(edit_y.begin(),edit_y.end(),y) - edit_y.begin();
}

void update(ll sex,ll node,ll L,ll R,ll l,ll r,ll gap){
    if(r < L || R < l) return;
    else if(l <= L && R <= r) cnt[node][sex] += gap;
    else{
        int M = (L+R)/2;
        update(sex,node*2,L,M,l,r,gap);
        update(sex,node*2+1,M+1,R,l,r,gap);
    }
    tree[node][sex] = 0;
    if(cnt[node][sex] > 0) tree[node][sex] = edit_y[R+1] - edit_y[L];
    else if(cnt[node][sex] == 0) tree[node][sex] = tree[node*2][sex] + tree[node*2+1][sex];
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        ll x1,x2,y1,y2,co;
        char c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        if(c == 'M') co = 1;
        else if(c == 'C') co = 2;
        else co = 4;
        edit_y.push_back(y1);
        edit_y.push_back(y2);
        v.push_back(vector<ll>{x1,1,y1,y2,co});
        v.push_back(vector<ll>{x2,-1,y1,y2,co});
    }
    sort(edit_y.begin(),edit_y.end());
    edit_y.erase(unique(edit_y.begin(),edit_y.end()),edit_y.end());
    sort(v.begin(),v.end());

    ll mx = edit_y.size()-2;
    ll INF = -1e9;
    ll pre_x[5];
    pre_x[1] = INF;
    pre_x[2] = INF;
    pre_x[4] = INF;

    for(int i=0; i<v.size(); i++){
        ll now_color = v[i][4];
        ll L = press(v[i][2]);
        ll R = press(v[i][3]) - 1;
        ll now_x = v[i][0];
        for(int j=1; j<=7; j++){
            if(j&now_color){
                ll diff = INF;
                for(int k=1; k<5; k<<=1){
                    if(k&j) diff = max(diff,pre_x[k]);
                }
                sum[j] += tree[1][j] * (now_x - diff);
                update(j,1,0,mx,L,R,v[i][1]);
            }
        }
        pre_x[now_color] = now_x;
    }
    ll C,M,Y,R,G,B,K;
    C = sum[7] - sum[5];
    M = sum[7] - sum[6];
    Y = sum[7] - sum[3];
    R = sum[7] - sum[2] - Y - M;
    G = sum[7] - sum[1] - Y - C;
    B = sum[7] - sum[4] - M - C;
    K = sum[7] - C - M - Y - R - G - B;
    cout << C << " " << M << " " << Y << " " << R << " " << G << " " << B << " " << K;
}
