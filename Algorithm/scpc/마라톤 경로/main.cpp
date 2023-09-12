#include <iostream>
#include <cmath>

using namespace std;

int a[101][101];
int mul[101][101][11];
int INF = 1000000;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int m,n,k;
        cin >> m >> n >> k;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                cin >> a[j][i];
                for(int l=0; l<=10; l++){
                    mul[j][i][l] = INF;
                }
            }
        }
        mul[0][0][0] = 0;
        int cnt = 0;
        for(int i=1; i<=m; i++){
            int tmp = mul[i-1][0][cnt];
            if(a[i][0] < 0 && cnt < 10) cnt++;
            mul[i][0][cnt] = tmp + abs(abs(a[i][0]) - abs(a[i-1][0]));
        }
        cnt = 0;
        for(int i=1; i<=n; i++){
            int tmp = mul[0][i-1][cnt];
            if(a[0][i] < 0 && cnt < 10) cnt++;
            mul[0][i][cnt] = tmp + abs(abs(a[0][i]) - abs(a[0][i-1]));
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[j][i] < 0){ //물개수 늘어남
                    for(int l=0; l<10; l++){
                        if(mul[j][i][l+1] > mul[j-1][i][l] + abs(abs(a[j][i]) - abs(a[j-1][i])))
                            mul[j][i][l+1] = mul[j-1][i][l] + abs(abs(a[j][i]) - abs(a[j-1][i]));
                        if(mul[j][i][l+1] > mul[j][i-1][l] + abs(abs(a[j][i]) - abs(a[j][i-1])))
                            mul[j][i][l+1] = mul[j][i-1][l] + abs(abs(a[j][i]) - abs(a[j][i-1]));
                    }
                    if(mul[j][i][10] > mul[j-1][i][10] + abs(abs(a[j][i]) - abs(a[j-1][i])))
                        mul[j][i][10] = mul[j-1][i][10] + abs(abs(a[j][i]) - abs(a[j-1][i]));
                    if(mul[j][i][10] > mul[j][i-1][10] + abs(abs(a[j][i]) - abs(a[j][i-1])))
                        mul[j][i][10] = mul[j][i-1][10] + abs(abs(a[j][i]) - abs(a[j][i-1]));
                }
                else{ //물개수 그대로
                    for(int l=0; l<=10; l++){
                        if(mul[j][i][l] > mul[j-1][i][l] + abs(abs(a[j][i]) - abs(a[j-1][i])))
                            mul[j][i][l] = mul[j-1][i][l] + abs(abs(a[j][i]) - abs(a[j-1][i]));
                        if(mul[j][i][l] > mul[j][i-1][l] + abs(abs(a[j][i]) - abs(a[j][i-1])))
                            mul[j][i][l] = mul[j][i-1][l] + abs(abs(a[j][i]) - abs(a[j][i-1]));
                    }
                }
            }
        }

        int mn = mul[m][n][k];
        for(int i=k+1; i<=10; i++){
            mn = min(mn, mul[m][n][i]);
        }

		cout << "Case #" << test_case+1 << endl;
		cout << mn << endl;
	}

	return 0;
}
