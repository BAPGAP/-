#include <iostream>
#include <vector>

using namespace std;

int n,k;

int board[15][15];
int dir[15];
int dead[15] = {0};
vector<int> top[15][15];
int locate[15][3];

int main()
{
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        board[i][0] = 2;
        board[0][i] = 2;
        board[i][n+1] = 2;
        board[n+1][i] = 2;
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    for(int i=1; i<=k; i++){
        int a,b,c;
        cin >> a >> b >> c;
        locate[i][0] = a;
        locate[i][1] = b;
        top[a][b].push_back(i);
        dir[i] = c;
    }
    int cnt = 0;
    while(1){
        for(int i=1; i<=k; i++){
            int dir_x, dir_y,now_x,now_y,new_x,new_y,color;
            dir_x = dir[i]/3;
            dir_y = 1 - dir_x;
            if(dir[i] == 3 || dir[i] == 2){
                dir_x *= -1;
                dir_y *= -1;
            }
            if(dead[i] == 0){
                now_x = locate[i][0];
                now_y = locate[i][1];
                new_x = locate[i][0] + dir_x;
                new_y = locate[i][1] + dir_y;
                color = board[new_x][new_y];
                if(color == 0){
                    int die = 0;
                    if(top[new_x][new_y].size() > 0) die = 1;
                    for(int j=0; j<top[now_x][now_y].size(); j++){
                        top[new_x][new_y].push_back(top[now_x][now_y][j]);
                    }
                    locate[i][0] = new_x;
                    locate[i][1] = new_y;
                    if(die == 1) dead[i] = 1;
                    vector<int>({}).swap(top[now_x][now_y]);
                }
                else if(color == 1){
                    int die = 0;
                    if(top[new_x][new_y].size() > 0) die = 1;
                    for(int j=top[now_x][now_y].size()-1; j>=0; j--){
                        top[new_x][new_y].push_back(top[now_x][now_y][j]);
                    }
                    dead[i] = 1;
                    if(die == 0){
                        int live = top[new_x][new_y][0];
                        dead[live] = 0;
                        locate[live][0] = new_x;
                        locate[live][1] = new_y;
                    }
                    vector<int>({}).swap(top[now_x][now_y]);
                }
                else{
                    if(dir[i]%2 == 0) dir[i] -= 1;
                    else dir[i] += 1;
                    dir_x = dir[i]/3;
                    dir_y = 1 - dir_x;
                    if(dir[i] == 3 || dir[i] == 2){
                        dir_x *= -1;
                        dir_y *= -1;
                    }
                    now_x = locate[i][0];
                    now_y = locate[i][1];
                    new_x = locate[i][0] + dir_x;
                    new_y = locate[i][1] + dir_y;
                    color = board[new_x][new_y];
                    if(color == 0){
                        int die = 0;
                        if(top[new_x][new_y].size() > 0) die = 1;
                        for(int j=0; j<top[now_x][now_y].size(); j++){
                            top[new_x][new_y].push_back(top[now_x][now_y][j]);
                        }
                        locate[i][0] = new_x;
                        locate[i][1] = new_y;
                        if(die == 1) dead[i] = 1;
                        vector<int>({}).swap(top[now_x][now_y]);
                    }
                    else if(color == 1){
                        int die = 0;
                        if(top[new_x][new_y].size() > 0) die = 1;
                        for(int j=top[now_x][now_y].size()-1; j>=0; j--){
                            top[new_x][new_y].push_back(top[now_x][now_y][j]);
                        }
                        dead[i] = 1;
                        if(die == 0){
                            int live = top[new_x][new_y][0];
                            dead[live] = 0;
                            locate[live][0] = new_x;
                            locate[live][1] = new_y;
                        }
                        vector<int>({}).swap(top[now_x][now_y]);
                    }
                }
            }
        }
        cnt++;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(top[i][j].size() >= 4){
                    cout << cnt;
                    return 0;
                }
            }
        }
        if(cnt > 1000){
            cout << "-1";
            return 0;
        }
    }
}
