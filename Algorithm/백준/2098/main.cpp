#include <iostream>

using namespace std;

int INF = 987654321;
int n;
int w[17][17];
int cost[17][1 << 16];

int dfs(int x,int visit){ //현재 x방문중 방문상태는 visit
    if(visit == (1 << n) - 1){
        if(w[x][0] == 0) return INF;
        else return w[x][0];
    }
    if(cost[x][visit] != 0) return cost[x][visit];

    cost[x][visit] = INF;

    for(int i=0; i<n; i++){
        if(visit & (1 << i)) continue; //이미 방문을 했거나
        if(w[x][i] == 0) continue; //가는 길이 없으면 continue
        cost[x][visit] = min(cost[x][visit],dfs(i, visit | (1 << i)) + w[x][i]);
    }
    return cost[x][visit];
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> w[i][j];
        }
    }
    cout << dfs(0,1);
}
