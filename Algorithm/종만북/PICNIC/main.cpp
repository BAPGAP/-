#include <iostream>

using namespace std;

bool check[10][10];
int jjack[10][10];
int pac[6] = {1,1,2,6,24,120};
int n,m;
int Answer;

void back_tracking(int x){
    if(x == n/2+1){
        Answer++;
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(!check[i][j]) continue;
            else if(jjack[i][j] == 0){
                jjack[i][j] = x;
                for(int k=0; k<n; k++){
                    if(jjack[i][k] == 0) jjack[i][k] = x;
                    if(jjack[k][i] == 0) jjack[k][i] = x;
                    if(jjack[j][k] == 0) jjack[j][k] = x;
                    if(jjack[k][j] == 0) jjack[k][j] = x;
                }
                back_tracking(x+1);
                jjack[i][j] = 0;
                for(int k=0; k<n; k++){
                    if(jjack[i][k] == x) jjack[i][k] = 0;
                    if(jjack[k][i] == x) jjack[k][i] = 0;
                    if(jjack[j][k] == x) jjack[j][k] = 0;
                    if(jjack[k][j] == x) jjack[k][j] = 0;
                }
            }
        }
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    for(int tc = 0; tc<T; tc++){
        Answer = 0;
        cin >> n >> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                check[i][j] = false;
                jjack[i][j] = 0;
            }
        }
        for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;
            check[x][y] = true;
            check[y][x] = true;
        }

        back_tracking(1);
        cout << Answer/pac[n/2] << "\n";
    }
}
