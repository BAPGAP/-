#include <iostream>

using namespace std;

int INF = 200000;
int n;
int w[20][20];
int dp[1 << 20] = {0};

int dfs(int x,int visit){ //x���� �湮���̰� ���� ������ visit �̴�
    if(visit == (1 << n) - 1) return 0;
    if(dp[visit] != 0) return dp[visit]; //�̹� �����ذ� ����

    dp[visit] = INF;

    for(int i=0; i<n; i++){
        if(visit & (1 << i)) continue; //�̹� �湮����
        dp[visit] = min(dp[visit],dfs(x+1,visit | (1 << i)) + w[i][x]);
    }
    return dp[visit];
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> w[i][j];
        }
    }
    cout << dfs(0,0);
}
