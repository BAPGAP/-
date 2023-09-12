#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v[20001];
bool finished[20001];
int d[20001];
bool check[20001];
vector<vector<int>> SCC;
stack<int> s;
int id = 0;
int SN = 0;
int print[20001];
int sn[20001];
vector<pair<int,int>> p;

// DFS는 총 정점의 갯수만큼 실행됩니다.
int dfs(int x) {
	d[x] = ++id; // 노드마다 고유한 번호 할당
	s.push(x); // 스택에 자기 자신을 삽입합니다.

	int parent = d[x];
	for(int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		// 방문하지 않은 이웃
		if(d[y] == 0)
			parent = min(parent, dfs(y));
		// 처리 중인 이웃
		else if(!finished[y])
			parent = min(parent, d[y]);
	}

	// 부모노드가 자기 자신인 경우
	if(parent == d[x]) {
		vector<int> scc;
		while(1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if(t == x) break;
		}
		SCC.push_back(scc);
		SN++;
	}

	// 자신의 부모 값을 반환한다.
	return parent;
}

int main()
{
    cin >> n >> m;
    int x,y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        int pos1,pos2;
        int not_pos1,not_pos2;
        if(x < 0){
            pos1 = 2*(-x) - 1;
            not_pos1 = pos1 + 1;
        }
        else{
            pos1 = 2*x;
            not_pos1 = pos1 - 1;
        }
        if(y < 0){
            pos2 = 2*(-y) - 1;
            not_pos2 = pos2 + 1;
        }
        else{
            pos2 = 2*y;
            not_pos2 = pos2 - 1;
        }
        v[not_pos1].push_back(pos2);
        v[not_pos2].push_back(pos1);
    }

    for(int i=1; i<=2*n; i++){
        d[i] = 0;
        finished[i] = false;
        check[i] = false;
        print[i] = -1;
    }

    for(int i = 1; i<= n*2; i++) {
		if(d[i] == 0) dfs(i);
	}

	for(int i = 0; i < SCC.size(); i++) {
		for(int j = 0; j < SCC[i].size(); j++) {
			int tmp = SCC[i][j];

			check[tmp] = true;
			int not_tmp;
			if(tmp%2 == 1) not_tmp = tmp+1;
			else not_tmp = tmp - 1;

			if(check[not_tmp]){
                cout << "0";
                return 0;
			}
		}
		for(int j = 0; j < SCC[i].size(); j++) {
			int tmp = SCC[i][j];
			check[tmp] = false;
		}
	}

	for(int i=1; i<=n*2; i++){
        p.push_back(make_pair(sn[i],i));
	}
    sort(p.begin(), p.end());

    for(int i=n*2; i>0; i--){
        int var = p[i].second;
        // 아직 해당 변수값이 설정되지 않았다면 지금 설정
        if(print[(var+1)/2] == -1) print[(var+1)/2] = var%2;
    }

	cout << "1\n";
	bool gogo = false;
	for(int i=1; i<=n; i++){
        if(print[i] == 1){
            if(!gogo){
                cout << "1";
                gogo = true;
            }
            else cout << " 1";
        }
        else{
            if(!gogo){
                cout << "0";
                gogo = true;
            }
            else cout << " 0";
        }
	}
	return 0;
}
