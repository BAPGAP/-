#include <iostream>
#include <string>
#include <queue>

using namespace std;
int n,m;
string board[11];

struct cord{
    int x,y;
};

struct state{
    cord red, blue, goal;
    int next;
    int cnt;
};
queue<state> BFS;

void check(cord red,cord blue, cord goal){
    board[red.x][red.y] = 'R';
    board[blue.x][blue.y] = 'B';
    board[goal.x][goal.y] = 'O';
    for(int i=0; i<n; i++){
        cout << board[i] << "\n";
    }
    board[red.x][red.y] = '.';
    board[blue.x][blue.y] = '.';
    board[goal.x][goal.y] = '.';
}


int main()
{
    cord red, blue, goal;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> board[i];
        for(int j=0; j<m; j++){
            if(board[i][j] == 'R'){
                red.x = i;
                red.y = j;
                board[i][j] = '.';
            }
            if(board[i][j] == 'B'){
                blue.x = i;
                blue.y = j;
                board[i][j] = '.';
            }
            if(board[i][j] == 'O'){
                goal.x = i;
                goal.y = j;
                board[i][j] = '.';
            }
        }
    }
    state tmp;
    BFS.push(tmp = {{red.x,red.y},{blue.x,blue.y},{goal.x,goal.y},0,0});
    BFS.push(tmp = {{red.x,red.y},{blue.x,blue.y},{goal.x,goal.y},1,0});
    BFS.push(tmp = {{red.x,red.y},{blue.x,blue.y},{goal.x,goal.y},2,0});
    BFS.push(tmp = {{red.x,red.y},{blue.x,blue.y},{goal.x,goal.y},3,0});
    while(!BFS.empty()){
        tmp = BFS.front();
        red = tmp.red;
        blue = tmp.blue;
        goal = tmp.goal;
        //check(red,blue, goal);
        int next = tmp.next;
        int next_x = next%2;
        int next_y = 1 - next%2;
        if(next >= 2){
            next_x *= -1;
            next_y *= -1;
        }
        int cnt = tmp.cnt;
        board[red.x][red.y] = 'R';
        board[blue.x][blue.y] = 'B';
        board[goal.x][goal.y] = 'O';
        BFS.pop();
        int rg=0, bg=0;
        while(1){
            int rcm=0,bcm=0;
            if(rg == 0){
                if(board[red.x + next_x][red.y + next_y] == '.'){
                    board[red.x][red.y] = '.';
                    red.x = red.x + next_x;
                    red.y = red.y + next_y;
                    board[red.x][red.y] = 'R';
                    rcm = 1;
                }
                else if(board[red.x + next_x][red.y + next_y] == 'O'){
                    board[red.x][red.y] = '.';
                    red.x = red.x + next_x;
                    red.y = red.y + next_y;
                    rcm = 1;
                    rg = 1;
                }
            }
            if(bg == 0){
                if(board[blue.x + next_x][blue.y + next_y] == '.'){
                    board[blue.x][blue.y] = '.';
                    blue.x = blue.x + next_x;
                    blue.y = blue.y + next_y;
                    board[blue.x][blue.y] = 'B';
                    bcm = 1;
                }
                else if(board[blue.x + next_x][blue.y + next_y] == 'O'){
                    board[blue.x][blue.y] = '.';
                    blue.x = blue.x + next_x;
                    blue.y = blue.y + next_y;
                    bcm = 1;
                    bg = 1;
                }
            }
            if(rcm == 0 && bcm == 0) break;
        }
        board[red.x][red.y] = '.';
        board[blue.x][blue.y] = '.';
        board[goal.x][goal.y] = '.';
        if(bg == 1){
            continue;
        }
        if(rg == 1){
            cout << cnt + 1;
            return 0;
        }
        cnt++;
        if(cnt <= 9){
            BFS.push(tmp = {{red.x,red.y},{blue.x,blue.y},{goal.x,goal.y},0,cnt});
            BFS.push(tmp = {{red.x,red.y},{blue.x,blue.y},{goal.x,goal.y},1,cnt});
            BFS.push(tmp = {{red.x,red.y},{blue.x,blue.y},{goal.x,goal.y},2,cnt});
            BFS.push(tmp = {{red.x,red.y},{blue.x,blue.y},{goal.x,goal.y},3,cnt});
        }
    }
    cout << "-1";
}

