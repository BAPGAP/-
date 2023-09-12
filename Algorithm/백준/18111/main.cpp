#include <iostream>

using namespace std;

int g[501][501];
int n,m,b;

int isok(int h){
    int sum = b;
    int t = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            sum += g[i][j] - h;
            if(h >= g[i][j]) t += h - g[i][j];
            else t += 2*(g[i][j] - h);
        }
    }
    if(sum < 0) return -1;
    else return t;
}

int main()
{
    cin >> n >> m >> b;
    int h_min = 987654321;
    int h_max = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
            if(h_min > g[i][j]) h_min = g[i][j];
            if(h_max < g[i][j]) h_max = g[i][j];
        }
    }
    int time = 987654321;
    int height;

    for(int i=h_min; i<=h_max; i++){
        int tmp = isok(i);
        if(tmp >= 0 && time >= tmp){
            time = tmp;
            height = i;
        }
    }
    cout << time << " " << height;
}
