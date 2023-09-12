#include <iostream>

using namespace std;

int A[101][101];
int B[101][101];

int main()
{
    int N,M,K;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> A[i][j];
        }
    }
    cin >> M >> K;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=K; j++){
            cin >> B[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            int sum = 0;
            for(int k=1; k<=M; k++){
                sum += A[i][k] * B[k][j];
            }
            cout << sum << " ";
        }
        cout << "\n";
    }
}
