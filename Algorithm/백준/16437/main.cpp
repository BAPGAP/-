#include <iostream>
#include <vector>

using namespace std;

vector<long long> adj[123457];
vector<long long> v;
bool visit[123457] = {0};

long long dfs(long long x){
    long long sum = v[x];
    visit[x] = true;
    bool isleaf = true;
    for(int i=0; i<adj[x].size(); i++){
        long long next = adj[x][i];
        if(!visit[next]){
            long long tmp = dfs(next);
            if(tmp > 0) sum += tmp;
            isleaf = false;
        }
    }
    if(isleaf) return v[x];

    return sum;
}

int main()
{
    int n;
    cin >> n;
    v.push_back(0);
    v.push_back(0);
    for(int i=2; i<=n; i++){
        string s;
        long long x,y;
        cin >> s >> x >> y;
        if(s == "W") x = -x;
        v.push_back(x);
        adj[i].push_back(y);
        adj[y].push_back(i);
    }
    cout << dfs(1);
}
