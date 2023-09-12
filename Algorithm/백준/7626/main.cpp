#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v; //y좌표, x1 , x2, 1 or -1 (1은 시작 -1은 끝)
vector<int> idx;

int getidx(int x){
    return lower_bound(idx.begin(),idx.end(),x) - idx.begin();
}

long long tree[1600009] = {0};
int cnt[1600009] = {0};

void update(int node,int L,int R,int l,int r,int gap){
    if(r < L || R < l) return;
    else if(l <= L && R <= r) cnt[node] += gap; //어차피 같은 구간 더하고 빼는 연산 반복이므로 굳이 게으른 '전파'할 필요 없음!
    else{
        int M = (L+R)/2;
        update(2*node,L,M,l,r,gap);
        update(2*node+1,M+1,R,l,r,gap);
    }
    tree[node] = 0;
    if(cnt[node] > 0) tree[node] = idx[R+1] - idx[L];
    else if(cnt[node] == 0 && L < R) tree[node] = tree[node*2] + tree[node*2+1];
}

int main()
{
    cin.tie(0);
	ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x1,x2,y1,y2;
        cin >> x1 >> x2 >> y1 >> y2;
        v.push_back(vector<int>{x1,y1,y2,1});
        v.push_back(vector<int>{x2,y1,y2,-1});
        idx.push_back(y1);
        idx.push_back(y2);
    }
    sort(idx.begin(),idx.end());
    idx.erase(unique(idx.begin(),idx.end()),idx.end());
    int ed = getidx(idx[idx.size()-1]);

    sort(v.begin(),v.end());

    long long pos = v[0][0];
    update(1,0,ed-1,getidx(v[0][1]),getidx(v[0][2])-1,v[0][3]);

    long long sum = 0;

    for(int i=1; i<v.size(); i++){
        sum += tree[1] * (long long)(v[i][0] - pos);
        pos = v[i][0];
        update(1,0,ed-1,getidx(v[i][1]),getidx(v[i][2])-1,v[i][3]);
    }

    cout << sum;
}
