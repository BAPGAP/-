#include <iostream>
#include <cstring>

using namespace std;

int v[51][51];
double dp[101][51]; //dp[x][y]�� x�Ͽ� y�� ������ ���� Ȯ��
double dim[51]; //�� ������ ����

int main()
{
    int T;
    cin >> T;
    while(T--){
        memset(dp,0,sizeof(dp));

        int n,d,p;
        cin >> n >> d >> p; // ���� ��  Ż���� d�ϵ�
        //�����Ұ� �ִ� ���� p   ������ 0 ~ n-1

        for(int i=0; i<n; i++){
            dim[i] = 0;
            for(int j=0; j<n; j++){
                cin >> v[i][j];
                dim[i] += v[i][j];
            }
        }
        dp[0][p] = 1;

        for(int i=1; i<=d; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(v[j][k]) dp[i][k] += dp[i-1][j] / dim[j];
                }
            }
        }

        int m;
        cin >> m;
        for(int i=1; i<=m; i++){
            int q;
            cin >> q;
            cout.precision(9);
            cout << dp[d][q] << " ";
        }
        cout << "\n";
    }
}
