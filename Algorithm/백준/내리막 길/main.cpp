#include <iostream>

using namespace std;

int p[501][501];
int check[501][501] = {0};
int ans[501][501] = {0};
int M,N;

int bfs(int x,int y){
    if(check[x][y] == 1){
        return ans[x][y];
    }
    if(x > 1 && p[x][y] > p[x-1][y]){
        ans[x][y] += bfs(x-1,y);
    }
    if(x < M && p[x][y] > p[x+1][y]){
        ans[x][y] += bfs(x+1,y);
    }
    if(y > 1 && p[x][y] > p[x][y-1]){
        ans[x][y] += bfs(x,y-1);
    }
    if(y < N && p[x][y] > p[x][y+1]){
        ans[x][y] += bfs(x,y+1);
    }
    check[x][y] = 1;
    return ans[x][y];
}




int main()
{
    cin >> M >> N;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cin >> p[i][j];
        }
    }
    ans[M][N] = 1;
    bfs(1,1);
    cout << ans[1][1];
}
