#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int INF = 2100000000;
vector<pair<int,int>> v[100001];
int c[100001][3];

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n,m,k;
	    int x,y,z;
	    cin >> n >> m >> k;
	    for(int i=1; i<=n; i++){
            c[i][0] = INF;
            c[i][2] = 0; //검사 완료 여부
	    }

	    for(int i=0; i<m; i++){
            cin >> x >> y >> z;
            v[x].push_back(make_pair(y,z));
            v[y].push_back(make_pair(x,z));
	    }
        for(int i=0; i<k; i++){
            cin >> x;
            c[x][0] = 0; //대피소면 대피소 까지 거리는 0
            c[x][1] = x; //가장 가까운 대피소는 자기 자신
            c[x][2] = 1; //검사할 필요 이제 없음
        }

	    priority_queue<pair<int,int>> q;


	    for(int i=1; i<=n; i++){
            if(c[i][0] == 0){
                for(int j=0; j<v[i].size(); j++){
                    int next = v[i][j].first;
                    if(c[next][0] == 0) continue;

                    int cost = v[i][j].second; //i -> next 비용

                    if(c[next][0] == cost){
                        c[next][1] = min(c[next][1],i);
                    }
                    else if(c[next][0] > cost){
                        c[next][0] = cost;
                        c[next][1] = i;
                        q.push(make_pair(-cost,next));
                    }
                }
            }
	    }

	    while(!q.empty()){
            int cost_total = -q.top().first;
            int node = q.top().second;
            q.pop();
            if(cost_total > c[node][0]) continue;

            for(int i=0; i<v[node].size(); i++){
                int next = v[node][i].first;
                if(c[next][2] == 1) continue; //이미 검사 완료

                int cost = v[node][i].second;

                if(c[next][0] == c[node][0] + cost){
                    c[next][1] = min(c[next][1],c[node][1]);
                    q.push(make_pair(-c[next][0],next));
                }
                else if(c[next][0] > c[node][0] + cost){
                    c[next][0] = c[node][0] + cost;
                    c[next][1] = c[node][1];
                    q.push(make_pair(-c[next][0],next));
                }
            }
            c[node][2] = 1;
        }

        long long int dis_sum = 0;
        long long int node_sum = 0;

        for(int i=1; i<=n; i++){
            dis_sum += c[i][0];
            node_sum += c[i][1];
            v[i].clear();
        }

		cout << "Case #" << test_case+1 << endl;
		cout << dis_sum << endl;
		cout << node_sum << endl;
	}

	return 0;
}
