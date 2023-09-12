#include <iostream>

using namespace std;

// 2^16 < 100000 < 2^17
int table[100001][17];
int len[100001];

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> table[i][0];
    }
    len[1] = 0;
    int cnt = 0;
    for(int i=2; i<=n; i++){
        if((1 << (cnt+1)) < i) cnt++;
        len[i] = cnt;
    }


    for(int j=1; j<=16; j++){
        for(int i=1; i<=n; i++){
            if(i + (1 << (j-1)) <= n) table[i][j] = min(table[i][j-1],table[i+(1 << (j-1))][j-1]);
        }
    }
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        int tmp = v - u + 1;
        int L = len[tmp];
        int Answer = min(table[u][L],table[v+1-(1 << L)][L]);

        /*  ¿ø·¡
        for(int j=16; j>=0; j--){
            if(tmp >= (1 << j)){
                Answer = min(Answer,table[u][j]);
                tmp -= (1 << j);
                u += (1 << j);
            }
        }
        */

        cout << Answer << "\n";
    }
}
