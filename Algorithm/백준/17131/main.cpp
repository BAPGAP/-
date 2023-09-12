#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> vp;
vector<int> idx;
long long tree[1000000] = {0};
long long p = 1e9 + 7;

bool compare(pair<int,int> x,pair<int,int> y){
    if(x.second == y.second) return x.first < y.first;
    return x.second > y.second;
}

int getidx(int x){
    return lower_bound(idx.begin(),idx.end(),x) - idx.begin();
}

long long gap(int node,int L,int R,int l,int r){
    if(l > r) return 0;

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

int line[200001];

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        vp.push_back({x,y});
        idx.push_back(x);
    }
    sort(idx.begin(),idx.end());
    idx.erase(unique(idx.begin(),idx.end()),idx.end());

    int ed = getidx(idx[idx.size()-1]);

    sort(vp.begin(),vp.end(),compare);
    long long answer = 0;
    int cnt = 1;
    line[0] = getidx(vp[0].first);
    int prey = vp[0].second;

    for(int i=1; i<vp.size(); i++){
        int y = vp[i].second;
        if(y == prey){
            line[cnt] = getidx(vp[i].first);
            cnt++;
            prey = vp[i].second;
        }
        else{
            for(int j=0; j<cnt; j++){
                answer += (gap(1,0,ed,0,line[j]-1) * gap(1,0,ed,line[j]+1,ed)) % p;
                answer %= p;
            }
            for(int j=0; j<cnt; j++){
                update(1,0,ed,line[j]);
            }
            line[0] = getidx(vp[i].first);
            cnt = 1;
            prey = vp[i].second;
        }
    }
    for(int j=0; j<cnt; j++){
        answer += (gap(1,0,ed,0,line[j]-1) * gap(1,0,ed,line[j]+1,ed)) % p;
        answer %= p;
    }
    cout << answer;
}
