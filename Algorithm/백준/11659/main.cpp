#include <iostream>

using namespace std;

int table[100000][17] = {0};

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> table[i][0];
    }
    for(int j=1; j<17; j++){
        for(int i=0; i<n; i++){
            if(i + (1<<j) <= n) table[i][j] = table[i][j-1] + table[i + (1<<(j-1))][j-1];
        }
    }

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        int sum = 0;
        int len = y - x + 1;
        for(int i=16; i>=0; i--){
            if(len >= (1<<i)){
                sum += table[x][i];
                x += (1<<i);
                len -= (1<<i);
            }
        }
        cout << sum << "\n";
    }

}
