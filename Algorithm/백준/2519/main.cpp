#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> adj[6001];

struct point{
    int x,y;
};
struct line{
    point P1,P2;
};

line L[3001];

bool CCW(line L1,line L2){
    int x1 = L1.P1.x;
    int y1 = L1.P1.y;
    int x2 = L1.P2.x;
    int y2 = L1.P2.y;
    int x3 = L2.P1.x;
    int y3 = L2.P1.y;
    int x4 = L2.P2.x;
    int y4 = L2.P2.y;

    int S1 = (x1*y2+x2*y3+x3*y1) - (x2*y1+x3*y2+x1*y3);
    if(S1 > 0) S1 = 1;
    else if(S1 < 0) S1 = -1;
    int S2 = (x1*y2+x2*y4+x4*y1) - (x2*y1+x4*y2+x1*y4);
    if(S2 > 0) S2 = 1;
    else if(S2 < 0) S2 = -1;
    int S3 = (x3*y4+x4*y1+x1*y3) - (x4*y3+x1*y4+x3*y1);
    if(S3 > 0) S3 = 1;
    else if(S3 < 0) S3 = -1;
    int S4 = (x3*y4+x4*y2+x2*y3) - (x4*y3+x2*y4+x3*y2);
    if(S4 > 0) S4 = 1;
    else if(S4 < 0) S4 = -1;

    if(S1*S2 <= 0 && S3*S4 <= 0) return true;
    else return false;
}

bool visit[6001] = {0};
int num[6001] = {0};
int cnt = 1;
int scc_cnt = 1;
int scc[6001];
stack<int> s;
int Answer[3001] = {0}; //0 : 아직 선택 안됨, 1 : 제거, 2 : 제거 X

int dfs(int x){
    num[x] = cnt++;
    s.push(x);
    int parent = num[x];
    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(num[next] == 0) parent = min(parent,dfs(next));
        else if(!visit[next]) parent = min(parent,num[next]);
    }

    if(parent == num[x]){
        while(1){
            int tmp = s.top();
            s.pop();
            visit[tmp] = true;
            scc[tmp] = scc_cnt;
            if(tmp == x) break;
        }
        scc_cnt++;
    }
    return parent;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=3*n; i++){
        cin >> L[i].P1.x >> L[i].P1.y >> L[i].P2.x >> L[i].P2.y;
    }
    for(int i=1; i<=3*n; i++){
        for(int j=i+1; j<=3*n; j++){
            if(CCW(L[i],L[j])){ //i번line, j번line이 한점에서 만나면
                int tmp1 = i;
                int tmp2 = j;
                int n_tmp1,n_tmp2;
                n_tmp1 = 2*tmp1;
                tmp1 = 2*tmp1 - 1;
                n_tmp2 = 2*tmp2;
                tmp2 = 2*tmp2 - 1;
                adj[n_tmp1].push_back(tmp2);
                adj[n_tmp2].push_back(tmp1);
            }
        }
    }
    for(int i=1; i<=3*n; i+=3){
        adj[2*i - 1].push_back(2*(i+1));
        adj[2*i - 1].push_back(2*(i+2));
        adj[2*(i+1) - 1].push_back(2*i);
        adj[2*(i+1) - 1].push_back(2*(i+2));
        adj[2*(i+2) - 1].push_back(2*i);
        adj[2*(i+2) - 1].push_back(2*(i+1));
    }

    for(int i=1; i<=6*n; i++){
        if(num[i] == 0) dfs(i);
    }
    bool ok = true;
    for(int i=1; i<=6*n; i+=2){
        if(scc[i] == scc[i+1]){
            ok = false;
            break;
        }
    }
    if(ok){
        vector<pair<int,int>> ggo;
        ggo.push_back({-1,0});
        for(int i=1; i<=6*n; i++){
            ggo.push_back({scc[i],i});
        }
        sort(ggo.begin(),ggo.end());
        vector<int> A;
        for(int i=6*n; i>0; i--){
            int fake_node = ggo[i].second;
            int real_node = (fake_node+1)/2;
            if(Answer[real_node] == 0){ //아직 선택안됨
                if(fake_node % 2 == 0){
                    Answer[real_node] = 1;
                    A.push_back(real_node);
                }
                else Answer[real_node] = 2;
            }
        }
        cout << A.size() << "\n";
        for(int i=A.size()-1; i>=0; i--){
            cout << A[i] << " ";
        }
    }
    else cout << "-1";
}
