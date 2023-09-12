#include <iostream>

using namespace std;

struct point{
    int x,y;
};

point P[8];

int s[101][101] = {0};

int main()
{
    for(int i=0; i<8; i++){
        cin >> P[i].x >> P[i].y;
    }
    for(int i=0; i<8; i+=2){
        for(int j=P[i].x; j<P[i+1].x; j++){
            for(int k=P[i].y; k<P[i+1].y; k++){
                s[j][k]++;
            }
        }
    }
    int cnt=0;
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            if(s[i][j] > 0) cnt++;
        }
    }
    cout << cnt;
}
