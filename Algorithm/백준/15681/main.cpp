#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];

bool visit[100001];
int numofnode[100001];

int make_tree(int x){
    visit[x] = true;
    int sumofnode = 1;
    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(!visit[next]){
            sumofnode += make_tree(next);
        }
    }
    return numofnode[x] = sumofnode;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,r,q;
    cin >> n >> r >> q;
    int x,y;
    for(int i=1; i<n; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        visit[i] = false;
    }
    visit[n] = false;
    make_tree(r);

    int tmp;
    for(int i=0; i<q; i++){
        cin >> tmp;
        cout << numofnode[tmp] << "\n";
    }
}
