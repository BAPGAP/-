#include <iostream>

using namespace std;

bool gamepan[22][22];
int Answer;
int H,W;

bool wansung(){
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if(!gamepan[i][j]) return false;
        }
    }
    return true;
}

void back_tracking(){
    if(wansung()){
        Answer++;
        return;
    }
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if(!gamepan[i][j]){
                if(!gamepan[i][j+1] && !gamepan[i+1][j+1]){
                   gamepan[i][j] = true;
                   gamepan[i][j+1] = true;
                   gamepan[i+1][j+1] = true;
                   back_tracking();
                   gamepan[i][j+1] = false;
                   gamepan[i+1][j+1] = false;
                   gamepan[i][j] = false;
                }
                if(!gamepan[i][j+1] && !gamepan[i+1][j]){
                    gamepan[i][j] = true;
                    gamepan[i][j+1] = true;
                    gamepan[i+1][j] = true;
                    back_tracking();
                    gamepan[i][j+1] = false;
                    gamepan[i+1][j] = false;
                    gamepan[i][j] = false;
                }
                if(!gamepan[i+1][j] && !gamepan[i+1][j-1]){
                    gamepan[i][j] = true;
                    gamepan[i+1][j] = true;
                    gamepan[i+1][j-1] = true;
                    back_tracking();
                    gamepan[i+1][j] = false;
                    gamepan[i+1][j-1] = false;
                    gamepan[i][j] = false;
                }
                if(!gamepan[i+1][j] && !gamepan[i+1][j+1]){
                    gamepan[i][j] = true;
                    gamepan[i+1][j] = true;
                    gamepan[i+1][j+1] = true;
                    back_tracking();
                    gamepan[i+1][j] = false;
                    gamepan[i+1][j+1] = false;
                    gamepan[i][j] = false;
                }
                return;
            }
        }
    }
}


int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        Answer = 0;
        cin >> H >> W;
        for(int i=0; i<=H+1; i++){
            for(int j=0; j<=W+1; j++){
                gamepan[i][j] = true;
            }
        }

        for(int i=1; i<=H; i++){
            for(int j=1; j<=W; j++){
                char c;
                cin >> c;
                if(c == '.') gamepan[i][j] = false;
            }
        }
        back_tracking();
        cout << Answer << "\n";
    }
}
