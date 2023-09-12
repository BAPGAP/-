#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int d[1001][1001];
int INF = 10000001;
int check[1001];
int cnt;

void go(int x, int y,int n){
    for(int i=1; i<=n; i++){
        if(d[x][i] + d[i][y] == d[x][y]){
            if(check[i] == 0){
                cnt++;
                check[i] = 1;
            }
            go(x,i,n);
            go(i,y,n);
        }
    }
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n,m;
	    cnt = 0;
        cin >> n >> m;
		for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                d[i][j] = INF;
                check[j] = 0;
            }
		}
		for(int i=0; i<m; i++){
            int a,b,c;
            cin >> a >> b >> c;
            d[a][b] = c;
            d[b][a] = c;
		}

		for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
                }
            }
		}

		for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i != j) go(i,j,n);
            }
		}

		cout << "Case #" << test_case+1 << endl;
		cout << n - cnt;
        for(int i=1; i<=n; i++){
            if(check[i] == 0) cout << " " << i;
        }
	}

	return 0;
}
