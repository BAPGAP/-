#include <iostream>

using namespace std;

long long arr[10][101] = {0};

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=9; i++){
        arr[i][1] = 1;
    }
    arr[0][1] = 0;
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j==0) arr[j][i] = arr[j+1][i-1]%1000000000;
            else if(j==9) arr[j][i] = arr[j-1][i-1]%1000000000;
            else arr[j][i] = (arr[j-1][i-1] + arr[j+1][i-1])%1000000000;
        }
    }
    long long sum = 0;
    for(int i=0; i<10; i++){
        sum += arr[i][n];
    }
    cout << sum%1000000000 << endl;
    return 0;
}
