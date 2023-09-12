#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v[300001];
vector<int> idx;

int max_size = 3000000;
pair<int,int> NIL = {0,-1};

vector<pair<int,int>> tree(max_size,NIL);
vector<pair<int,int>> lazy(max_size,NIL);

void update_lazy(int node,int L,int R){
    tree[node] = max(tree[node],lazy[node]);
    if(L != R){
        lazy[2*node] = max(lazy[node],lazy[2*node]);
        lazy[2*node+1] = max(lazy[node],lazy[2*node+1]);
    }
    lazy[node] = NIL;
}

void update(int node,int L,int R,int l,int r,pair<int,int> gap){
    if(lazy[node] != NIL) update_lazy(node,L,R);

    if(r < L || R < l) return;
    else if(l <= L && R <= r){
        lazy[node] = gap;
        update_lazy(node,L,R);
    }
    else{
        int M = (L+R)/2;
        update(2*node,L,M,l,r,gap);
        update(2*node+1,M+1,R,l,r,gap);
        tree[node] = max(tree[node*2],tree[node*2+1]);
    }
}

pair<int,int> sv(int node,int L,int R,int l,int r){
    if(lazy[node] != NIL) update_lazy(node,L,R);

    int M = (L+R)/2;

    if(r < L || R < l) return NIL;
    else if(l <= L && R <= r) return tree[node];
    else return max(sv(2*node,L,M,l,r),sv(2*node+1,M+1,R,l,r));
}

int getidx(int x){
    return lower_bound(idx.begin(), idx.end(), x) - idx.begin();
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(vector<int>{b,c});
        idx.push_back(b);
        idx.push_back(c);
    }
    //ÁÂÇ¥ ¾ÐÃà
    sort(idx.begin(),idx.end());
    idx.erase(unique(idx.begin(),idx.end()),idx.end());

    int ed = getidx(idx[idx.size()-1]);

    vector<int> parent(n+1,-1);

    for(int i=1; i<=n; i++){
        pair<int,int> mx = NIL;
        for(int j=0; j<v[i].size(); j++){
            int x = getidx(v[i][j][0]);
            int y = getidx(v[i][j][1]);
            mx = max(mx,sv(1,0,ed,x,y));
        }

        parent[i] = mx.second;
        mx.first++;
        mx.second = i;

        for(int j=0; j<v[i].size(); j++){
            int x = getidx(v[i][j][0]);
            int y = getidx(v[i][j][1]);
            update(1,0,ed,x,y,mx);
        }
    }

    bool visit[n+1] = {0};
    pair<int,int> MX = sv(1,0,ed,0,ed);
    int pos = MX.second;
    while(pos != -1){
        visit[pos] = true;
        pos = parent[pos];
    }

    cout << n - MX.first << "\n";
    for(int i=1; i<=n; i++){
        if(!visit[i]) cout << i << " ";
    }
}
