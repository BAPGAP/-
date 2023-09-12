#include <iostream>

using namespace std;

int n;
int pan[101][101];
int J[101][101];

void dfs(int x,int y){
    int tmp = pan[x][y];
    //R    x,y+tmp
    if(y + tmp <= n && J[x][y+tmp] == 0){
        J[x][y+tmp] = J[x][y] + 1;
        dfs(x,y+tmp);
    }
    //D    x+tmp,y
    if(x + tmp <= n && J[x+tmp][y] == 0){
        J[x+tmp][y] = J[x][y] + 1;
        dfs(x+tmp,y);
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> pan[i][j];
                J[i][j] = 0;
            }
        }
        J[1][1] = 1;
        dfs(1,1);
        if(J[n][n] != 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
