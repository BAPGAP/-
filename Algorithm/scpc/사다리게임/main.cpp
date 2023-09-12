#include <iostream>
#include <algorithm>

using namespace std;

int INF = 10000;
int gil[1501][1501];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n,k,m;
        cin >> n >> k >> m;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                gil[i][j] = INF;
            }
        }
        for(int i=1; i<=n; i++){
            gil[i][i] = 0;
        }

        int x,y;
        for(int i=0; i<k; i++){
            cin >> x >> y;
            for(int j=1; j<=n; j++){
                int tmp1 = gil[j][x];
                int tmp2 = gil[j][y];
                gil[j][x] = min(tmp1+1,tmp2);
                gil[j][y] = min(tmp1,tmp2+1);
            }
        }

        int sum = 0;

        for(int i=0; i<m; i++){
            cin >> x >> y;
            if(gil[x][y] == INF) sum += -1;
            else sum += gil[x][y];
        }

		cout << "Case #" << test_case+1 << endl;
		cout << sum << endl;
	}

	return 0;
}
