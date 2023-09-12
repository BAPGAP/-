#include <iostream>

using namespace std;

char jido[101][101];
bool visit[101][101] = {0};

void dfs(int x,int y){
    visit[x][y] = true;
    int tmp = x;
    while(1){
        if(jido[tmp-1][y] == '#') break;
        else if(jido[tmp-1][y] == '+'){
            tmp--;
        }
        else{
            tmp--;
            break;
        }
    }
    if(!visit[tmp][y]) dfs(tmp,y);

    tmp = x;
    while(1){
        if(jido[tmp+1][y] == '#') break;
        else if(jido[tmp+1][y] == '+'){
            tmp++;
        }
        else{
            tmp++;
            break;
        }
    }
    if(!visit[tmp][y]) dfs(tmp,y);


    tmp = y;
    while(1){
        if(jido[x][tmp-1] == '#') break;
        else if(jido[x][tmp-1] == '+'){
            tmp--;
        }
        else{
            tmp--;
            break;
        }
    }
    if(!visit[x][tmp]) dfs(x,tmp);

    tmp = y;
    while(1){
        if(jido[x][tmp+1] == '#') break;
        else if(jido[x][tmp+1] == '+'){
            tmp++;
        }
        else{
            tmp++;
            break;
        }
    }
    if(!visit[x][tmp]) dfs(x,tmp);
}


int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> jido[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(jido[i][j] == 'W'){
                dfs(i,j);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(jido[i][j] == '.' && !visit[i][j]) cout << "P";
            else cout << jido[i][j];
        }
        cout << "\n";
    }
}
