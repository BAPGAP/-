#include<iostream>

using namespace std;

int cnt[101][101][101] = {0};

void w(int a,int b,int c){
    if(a<=50 || b<=50 || c<=50){cnt[a][b][c] = 1; return;}
    if(a>70 || b>70 || c>70){
        if(cnt[70][70][70] == 0){
            w(70,70,70);
        }
        cnt[a][b][c] = cnt[70][70][70];
        return;
    }
    if(a<b && b<c){
        if(cnt[a][b][c-1] == 0){
            w(a,b,c-1);
        }
        if(cnt[a][b-1][c-1] == 0){
            w(a,b-1,c-1);
        }
        if(cnt[a][b-1][c] == 0){
            w(a,b-1,c);
        }
        cnt[a][b][c] = cnt[a][b][c-1] + cnt[a][b-1][c-1] - cnt[a][b-1][c];
        return;
    }

    if(cnt[a-1][b][c] == 0){
        w(a-1,b,c);
    }
    if(cnt[a-1][b-1][c] == 0){
        w(a-1,b-1,c);
    }
    if(cnt[a-1][b][c-1] == 0){
        w(a-1,b,c-1);
    }
    if(cnt[a-1][b-1][c-1] == 0){
        w(a-1,b-1,c-1);
    }

    cnt[a][b][c] = cnt[a-1][b][c] + cnt[a-1][b-1][c] + cnt[a-1][b][c-1] - cnt[a-1][b-1][c-1];

}

int main(){
    int x,y,z;
    while(1){
        cin >> x >> y >> z;
        if(x == -1 && y == -1 && z == -1) break;
        w(x+50,y+50,z+50);
        cout << "w(" << x << ", " << y << ", " << z << ") = " << cnt[x+50][y+50][z+50] << "\n";
    }

}
