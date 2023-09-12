#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

map<string,int> M;
vector<pair<int,int>> vp;
queue<string> q;

int bfs(string x){
    q.push(x);
    M[x] = 0;
    while(!q.empty()){
        string node = q.front();
        q.pop();

        for(int i=0; i<node.size(); i++){
            for(int j=i+1; j<node.size(); j++){
                string next = node;
                reverse(next.begin()+i,next.begin()+j+1);

                if(M.find(next) == M.end()){
                    q.push(next);
                    M[next] = M[node] + 1;
                }
            }
        }
    }
}

int main()
{
    string original = "";
    for(int i=1; i<=8; i++){
        original += to_string(i);
        bfs(original);
    }

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            vp.push_back({x,i});
        }
        sort(vp.begin(),vp.end());
        string tmp = ""; //만들어야되는거
        for(int i=0; i<vp.size(); i++){
            tmp += to_string(vp[i].second);
        }
        cout << M[tmp] << "\n";
        vector<pair<int,int>>().swap(vp);
    }
}
