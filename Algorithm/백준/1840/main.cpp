#include <iostream>

using namespace std;

int sudo[10][10] = {0};
int node[10][10][10] = {0};

void in(int x,int y,int z){
    for(int i=1; i<=9; i++){
        node[x][i][z] = 1;
        node[i][y][z] = 1;
    }
    int tmp1=x,tmp2=y;
    if(x%3==2) tmp1 -= 1;
    else if(x%3==0) tmp1 -= 2;
    if(y%3==2) tmp2 -= 1;
    else if(y%3==0) tmp2 -= 2;

    for(int i=tmp1; i<=tmp1+2; i++){
        for(int j=tmp2; j<=tmp2+2; j++){
            node[i][j][z] = 1;
        }
    }
    sudo[x][y] = z;
    for(int i=1; i<=9; i++){
        node[x][y][i] = 1;
    }
    node[x][y][z] = 0;
}

bool check(){
    //row
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            int sum = 0;
            for(int k=1; k<=9; k++){
                sum += node[i][k][j];
            }
            if(sum == 9) return false;
        }
    }

    //col
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            int sum = 0;
            for(int k=1; k<=9; k++){
                sum += node[k][i][j];
            }
            if(sum == 9) return false;
        }
    }
    for(int i=1; i<=9; i+=3){
        for(int j=1; j<=9; j+=3){
            for(int x=1; x<=9; x++){
                int sum = 0;
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        sum += node[i+k][j+l][x];
                    }
                }
                if(sum == 9) return false;
            }
        }
    }

    return true;
}

int main()
{
    int pos = -1;
    for(int T=1; T<=81; T++){
        int a,b,c;
        cin >> a >> b >> c;
        if(pos > 0) continue;

        if(sudo[a][b] != 0 || node[a][b][c] == 1){
            pos = T;
            continue;
        }

        in(a,b,c);

        if(check()){}
        else pos = T;
        /*
        for(int i=1; i<=9; i++){
            for(int j=1; j<=9; j++){
                cout << i << " , " << j << " : ";
                for(int k=1; k<=9; k++){
                    cout << node[i][j][k] << " ";
                }
                cout << "\n";
            }
        }
        */

    }
    cout << pos;
}
