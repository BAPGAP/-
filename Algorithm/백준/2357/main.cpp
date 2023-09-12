#include <iostream>

using namespace std;
typedef long long ll;

ll min_table[100000][17] = {0};
ll max_table[100000][17] = {0};

ll half[100000];
ll two[17];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    int cnt = 0;
    for(int i=1; i<=n; i++){
        cin >> min_table[i-1][0];
        max_table[i-1][0] = min_table[i-1][0];
        half[i] = cnt;
        if((1<<cnt+1) == i) cnt++;
    }
    two[0] = 1;
    for(int j=1; j<17; j++){
        two[j] = two[j-1]*2;
        for(int i=0; i<n; i++){
            if(i + two[j] > n) continue;
            max_table[i][j] = max(max_table[i][j-1],max_table[i+two[j-1]][j-1]);
            min_table[i][j] = min(min_table[i][j-1],min_table[i+two[j-1]][j-1]);
        }
    }

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        int len = y-x+1;
        int L = half[len];
        int R = two[L];
        cout << min(min_table[x][L],min_table[y+1-R][L]) << " ";
        cout << max(max_table[x][L],max_table[y+1-R][L]) << "\n";
    }
}
