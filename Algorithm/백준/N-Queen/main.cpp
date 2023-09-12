#include <iostream>

using namespace std;

int queen[15][15]={0};
int n, sum = 0;

void go(int x){
    if(x == n-1){
        for(int i=0; i<n; i++){
            if(queen[i][n-1] == 0){
                sum++;
            }
        }
        return;
    }
    for(int j=0; j<n; j++){
        if(queen[j][x] == 0){
            queen[j][x] = x+1;
            for(int k=1; k<n; k++){
                if(x+k < n && queen[j][x+k] == 0) queen[j][x+k] = x+1;
                if(x+k < n && j+k < n && queen[j+k][x+k] == 0) queen[j+k][x+k] = x+1;
                if(x+k < n && j-k >= 0 && queen[j-k][x+k] == 0) queen[j-k][x+k] = x+1;
            }
            go(x+1);
            queen[j][x] = 0;
            for(int k=1; k<n; k++){
                if(x+k < n && queen[j][x+k] == x+1) queen[j][x+k] = 0;
                if(x+k < n && j+k < n && queen[j+k][x+k] == x+1) queen[j+k][x+k] = 0;
                if(x+k < n && j-k >= 0 && queen[j-k][x+k] == x+1) queen[j-k][x+k] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;
    go(0);
    cout << sum;
    return 0;
}
