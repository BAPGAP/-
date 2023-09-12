#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int Answer;
int n,m;
vector<int> v[200001];

void go(int x){
    //v[x][0] v[x][1] 연결 되어 있음?
    bool ok = true;
    for(int i=0; i<v[v[x][0]].size(); i++){
        if(v[v[x][0]][i] == v[x][1]) ok = false;
    }
    if(ok) return;

    //연결되어있으면
    int tmp1 = v[x][0];
    int tmp2 = v[x][1];

    v[x].clear();
    for(int i=0; i<v[tmp1].size(); i++){
        if(v[tmp1][i] == x){v[tmp1].erase(v[tmp1].begin() + i); break;}
    }
    for(int i=0; i<v[tmp2].size(); i++){
        if(v[tmp2][i] == x){v[tmp2].erase(v[tmp2].begin() + i); break;}
    }

    if(v[tmp1].size() == 2) go(tmp1);
    if(v[tmp2].size() == 2) go(tmp2);
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> n >> m;
        int x,y;
        for(int i=0; i<m; i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        queue<int> q;

        for(int i=1; i<=n; i++){
            if(v[i].size() == 2) q.push(i);
        }

        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            go(tmp);
        }

        Answer = 0;

		for(int i=1; i<=n; i++){
            if(v[i].size() > 0) Answer++;
		}


		for(int i=1; i<=n; i++){
            v[i].clear();
		}

		cout << "Case #" << test_case+1 << "\n" << Answer << endl;
	}

	return 0;
}
