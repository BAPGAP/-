#include <iostream>

using namespace std;
int sudo[10][10];
int c[82];
int r[82];
int cnt;
int ed = 0;

int ch(int n,int m,int z){
    sudo[n][m] = z;
    for(int i=0; i<9; i++){
        if(sudo[n][m] == sudo[n][i] && m != i){
            sudo[n][m] = 0;
            return 0;
        }
    }
    for(int i=0; i<9; i++){
        if(sudo[n][m] == sudo[i][m] && n != i){
            sudo[n][m] = 0;
            return 0;
        }
    }
    int x = n - n%3;
    int y = m - m%3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(sudo[n][m] == sudo[x+i][y+j]){
                if(n != x+i || m != y+j){
                    sudo[n][m] = 0;
                    return 0;
                }
            }
        }
    }
    sudo[n][m] = 0;
    return 1;
}
void go(int x){

    if(ed == 1) return;

    if(x == cnt){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << sudo[i][j] << " ";
            }
            cout << "\n";
        }
        ed = 1;
        return;
    }

    for(int i=1; i<=9; i++){
        if(ch(c[x],r[x],i)){
            sudo[c[x]][r[x]] = i;
            go(x+1);
            sudo[c[x]][r[x]] = 0;
        }
    }

}

int main()
{
    cnt=0;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudo[i][j];
            if(sudo[i][j] == 0){
                c[cnt] = i;
                r[cnt] = j;
                cnt++;
            }
        }
    }

    go(0);

    return 0;
}
