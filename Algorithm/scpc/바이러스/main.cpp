#include <iostream>

using namespace std;

int k,l,n,m;
int n_now; //현재 살아있는 점 개수
int dim[101];
int v[101][101];

void p(){ //0 < 차수 < k || n_now - l - 1 < 차수 인 점있으면 폐기하고 반복
    /*for(int i=1; i<=n; i++){
        cout << dim[i] << " ";
    }
    cout << "\n";
    cout << n_now << "\n";
    */
    for(int i=1; i<=n; i++){
        if(dim[i] == 0) continue;
        if(dim[i] < k || n_now - l - 1 < dim[i]){
            for(int j=1; j<=n; j++){
                if(v[i][j] == 1 || v[j][i] == 1){
                    v[i][j] = 0;
                    v[j][i] = 0;
                    dim[i]--;
                    dim[j]--;
                    if(dim[i] == 0) n_now--;
                    if(dim[j] == 0) n_now--;
                }
            }
            p();
        }
    }
    return;
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> k >> l >> n >> m;

        for(int i=1; i<=n; i++){
            dim[i] = 0;
            for(int j=1; j<=n; j++){
                v[i][j] = 0;
            }
        }
        n_now = 0;
        int x,y;
        for(int i=0; i<m; i++){
            cin >> x >> y;
            v[x][y] = 1;
            v[y][x] = 1;
            dim[x]++;
            dim[y]++;
        }
        for(int i=1; i<=n; i++){
            if(dim[i] != 0) n_now++;
        }

        p();   //이제 모든 점의 차수는 k <= 차수 <= n_now - l - 1;

        int sum = 0;
        for(int i=1; i<=n; i++){
            if(dim[i] == 0) sum += i;
        }

		cout << "Case #" << test_case+1 << endl;
		cout << sum << endl;
	}

	return 0;
}
