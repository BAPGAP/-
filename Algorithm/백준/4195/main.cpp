#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<string,int> M;
map<string,int>::iterator iter;
int cnt;
int parent[200002];
int height[200002];
int group[200002];

int Find(int x){
    if(x == parent[x]) return x;
    else{
        return parent[x] = Find(parent[x]);
    }
}

void Merge(int x,int y){
    x = Find(x);
    y = Find(y);

    if(x == y) return;

    if(height[x] > height[y]) swap(x,y);

    parent[x] = y;

    if(height[x] == height[y]) height[y]++;

    int tmp = group[x] + group[y];
    group[x] = tmp;
    group[y] = tmp;
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        cnt = 0;
        int F;
        cin >> F;

        for(int i=0; i<=2*F; i++){
            parent[i] = i;
            height[i] = 1;
            group[i] = 1;
        }

        string s1,s2;
        int node1,node2;
        for(int i=0; i<F; i++){
            cin >> s1 >> s2;
            if(M.find(s1) == M.end()){
                M[s1] = cnt;
                node1 = cnt;
                cnt++;
            }
            else node1 = M[s1];
            if(M.find(s2) == M.end()){
                M[s2] = cnt;
                node2 = cnt;
                cnt++;
            }
            else node2 = M[s2];
            Merge(node1,node2);
            cout << group[Find(node1)] << "\n";
        }

        M.erase(M.begin(),M.end());
    }

}
