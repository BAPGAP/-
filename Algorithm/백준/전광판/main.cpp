#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

int R[101][101]; //R[?][?]의 node 번호
int C[101][101];
int cnt;

vector<int> CR[40004]; //번호준 node 스위치 종류 저장  (1 = true, 0 = false) (1 = R, 0 = C) (i,j)

int parent[40004];
int height[40004];

int check_R[101][101]; // -1 : 아직 안정해짐 , 0 : 끈다 , 1 : 킨다
int check_C[101][101];

vector<int> adj[40001];
bool visit[40001];

void del(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            C[i][j] = 0;
            check_C[i][j] = -1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            R[i][j] = 0;
            check_R[i][j] = -1;
        }
    }
    for(int i=1; i<=4*n*m; i++){
        parent[i] = i;
        height[i] = 1;
        visit[i] = false;
    }
}

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int u,int v){
    int x = Find(u);
    int y = Find(v);
    if(x == y) return;

    if(height[x] > height[y]) swap(x,y);
    parent[x] = y;
    if(height[x] == height[y]) height[y]++;
}

void dfs(int x,int b){
    visit[x] = true;
    //부모가 x인 친구들 모두 b로 정하기
    for(int i=1; i<cnt; i+=2){ //본체만 정함
        if(parent[i] == x){
            if(CR[i][1] == 1){ //R
                check_R[CR[i][2]][CR[i][3]] = b;
            }
            else{
                check_C[CR[i][2]][CR[i][3]] = b;
            }
        }
    }

    for(int i=0; i<adj[x].size(); i++){
        int next = adj[x][i];
        if(!visit[next]) dfs(next,1-b);
    }
}

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    cnt = 1;
        cin >> n >> m;
		del();

		int x,a,b;
		for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> x >> a >> b;
                if(R[i][a] == 0){
                    R[i][a] = cnt;
                    CR[cnt].push_back(1);
                    CR[cnt].push_back(1);
                    CR[cnt].push_back(i);
                    CR[cnt].push_back(a);
                    CR[cnt+1].push_back(0);
                    CR[cnt+1].push_back(1);
                    CR[cnt+1].push_back(i);
                    CR[cnt+1].push_back(a);
                    cnt += 2;
                }
                if(C[j][b] == 0){
                    C[j][b] = cnt;
                    CR[cnt].push_back(1);
                    CR[cnt].push_back(0);
                    CR[cnt].push_back(j);
                    CR[cnt].push_back(b);
                    CR[cnt+1].push_back(0);
                    CR[cnt+1].push_back(0);
                    CR[cnt+1].push_back(j);
                    CR[cnt+1].push_back(b);
                    cnt += 2;
                }

                //node 연결상태
                if(x == 1){
                    Union(R[i][a],C[j][b]);
                    Union(R[i][a]+1,C[j][b]+1);
                }
                else{
                    Union(R[i][a]+1,C[j][b]);
                    Union(R[i][a],C[j][b]+1);
                }
            }
		}
 		bool possible = true;
        for(int i=1; i<cnt; i+=2){
            if(Find(i) == Find(i+1)){
                cout << "Case #" << test_case+1 << "\nImpossible" << "\n";
                possible = false;
                break;
            }
        }
        if(possible){
            for(int i=1; i<cnt; i+=2){
                bool ok = true;
                for(int j=0; j<adj[parent[i]].size(); j++){
                    if(adj[parent[i]][j] == parent[i+1]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    adj[parent[i]].push_back(parent[i+1]);
                    adj[parent[i+1]].push_back(parent[i]);
                }
            }
            for(int i=1; i<cnt; i++){
                if(adj[i].size() != 0 && !visit[i]) dfs(i,0);
            }

            cout << "Case #" << test_case+1 << "\n";

            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(check_C[i][j] == 0){
                        cout << "C";
                        if(i < 10) cout << "0" << i;
                        else cout << i;

                        if(j < 10) cout << "0" << j;
                        else cout << j;
                        cout << " ";
                    }
                }
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(check_R[i][j] == 0){
                        cout << "R";
                        if(i < 10) cout << "0" << i;
                        else cout << i;

                        if(j < 10) cout << "0" << j;
                        else cout << j;
                        cout << " ";
                    }
                }
            }
            cout << "\n";
        }

        for(int i=0; i<cnt; i++){
            vector<int> ().swap(CR[i]);
            vector<int> ().swap(adj[i]);
        }
	}
	return 0;
}
