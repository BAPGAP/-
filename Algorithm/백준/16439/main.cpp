#include <iostream>

using namespace std;

int chicken[31][31];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> chicken[i][j];
        }
    }
    int mx = -1;
    for(int i=1; i<=m; i++){
        for(int j=i+1; j<=m; j++){
            for(int k=j+1; k<=m; k++){
                int sum = 0;
                for(int l=1; l<=n; l++){
                    int tmp = max(chicken[l][i],chicken[l][j]);
                    tmp = max(tmp,chicken[l][k]);
                    sum += tmp;
                }
                if(sum > mx) mx = sum;
            }
        }
    }
    cout << mx;
}
