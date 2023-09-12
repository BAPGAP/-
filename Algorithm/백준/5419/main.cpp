#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int,int>> vp;
vector<int> idx;

bool compare(pair<int,int> x,pair<int,int> y){
    if(x.first == y.first) return x.second > y.second;
    return x.first <  y.first;
}

int getindex(int x){
    return lower_bound(idx.begin(),idx.end(),x) - idx.begin();
}

long long tree[300004];

long long gap(int node,int L,int R,int l,int r){
    if(r < L || R < l) return 0;
    else if(l <= L && R <= r) return tree[node];
    else{
        int M = (L+R)/2;
        return gap(2*node,L,M,l,r) + gap(2*node+1,M+1,R,l,r);
    }
}

void update(int node,int L,int R,int pos){
    if(pos < L || R < pos) return;
    tree[node] += 1;
    if(L == R) return;
    int M = (L+R)/2;
    update(2*node,L,M,pos);
    update(2*node+1,M+1,R,pos);
}

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            vp.push_back({x,y});
            idx.push_back(y);
        }
        sort(vp.begin(),vp.end(),compare);
        sort(idx.begin(),idx.end());
        idx.erase(unique(idx.begin(),idx.end()),idx.end());
        int ed = getindex(idx[idx.size()-1]);
        memset(tree,0,sizeof tree);

        long long sum = 0;

        for(int i=0; i<vp.size(); i++){
            int tmp = getindex(vp[i].second);
            sum += gap(1,0,ed,tmp,ed);
            update(1,0,ed,tmp);
        }
        cout << sum << "\n";
        vector<pair<int,int>>().swap(vp);
        vector<int>().swap(idx);
    }
}
