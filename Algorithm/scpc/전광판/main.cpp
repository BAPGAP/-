#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

int R[101][101];
int C[101][101];
int cnt;
int scc_num;
int id;
vector<int> v[40004];
bool finish[40004];
int node[40004];
stack<int> s;
vector<int> CR[40004]; //��ȣ�� node ����ġ ���� ����  (1 = true, 0 = false) (1 = R, 0 = C) (i,j)

int scc_include[40004]; //�� node�� � scc�� ���ϴ��� �˷���

int check_R[101][101]; // -1 : ���� �������� , 0 : ���� , 1 : Ų��
int check_C[101][101];

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
}

int dfs(int x){
    node[x] = ++id;
	s.push(x); // ���ÿ� �ڱ� �ڽ��� �����մϴ�.

	int parent = node[x];
	for(int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];

		// �湮���� ���� �̿�
		if(node[y] == 0)
			parent = min(parent, dfs(y));
		// ó�� ���� �̿�
		else if(!finish[y])
			parent = min(parent, node[y]);
	}

	// �θ��尡 �ڱ� �ڽ��� ���
	if(parent == node[x]) {
		while(1) {
			int t = s.top();
			s.pop();
			scc_include[t] = scc_num;
			finish[t] = true;
			if(t == x) break;
		}
	}
    scc_num++;

	// �ڽ��� �θ� ���� ��ȯ�Ѵ�.
	return parent;

}

int main(int argc, char** argv)
{
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

                //node �������
                if(x == 1){ // (~p|q) & (p|~q)
                    v[R[i][a]].push_back(C[j][b]);
                    v[C[j][b]].push_back(R[i][a]);
                    v[R[i][a]+1].push_back(C[j][b]+1);
                    v[C[j][b]+1].push_back(R[i][a]+1);
                }
                else{ // (p|q) & (~p|~q)
                    v[R[i][a]+1].push_back(C[j][b]);
                    v[C[j][b]+1].push_back(R[i][a]);
                    v[R[i][a]].push_back(C[j][b]+1);
                    v[C[j][b]].push_back(R[i][a]+1);
                }
            }
		}

		for(int i=1; i<cnt; i++){
            finish[i] = false;
            node[i] = 0; //������ȣ (�湮 ����)
		}
        id = 0;
        scc_num = 1;
		for(int i=1; i<cnt; i++){
            if(node[i] == 0){
                dfs(i);
            }
		}

		bool possible = true;
        for(int i=1; i<=cnt/2; i++){
            if(scc_include[2*i] == scc_include[2*i-1]){
                cout << "Case #" << test_case+1 << "\nImpossible" << "\n";
                possible = false;
                break;
            }
        }
        if(possible){
            vector<pair<int,int>> P;
            for(int i=1; i<cnt; i++){
                P.push_back(make_pair(scc_include[i],i));
            }
            sort(P.begin(),P.end());
            for(int i=P.size()-1; i>0; i--){
                //�� i�� ���� ���� ����
                int tmp = P[i].second;
                if(CR[tmp][1] == 1 && check_R[CR[tmp][2]][CR[tmp][3]] == -1){ //R����ġ ���� �ȴ�������
                    check_R[CR[tmp][2]][CR[tmp][3]] = 1 - CR[tmp][0];
                }
                else if(CR[tmp][1] == 0 && check_C[CR[tmp][2]][CR[tmp][3]] == -1){ //C����ġ ���� �ȴ�������
                    check_C[CR[tmp][2]][CR[tmp][3]] = 1 - CR[tmp][0];
                }
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
            vector<int> ().swap(v[i]);
            vector<int> ().swap(CR[i]);
        }
	}
	return 0;
}
