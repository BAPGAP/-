#include <iostream>

using namespace std;

int sum1[41]={0};
int sum2[41]={0};

void fibo(int n){
    if(n == 0) {sum1[0] = 1; return;}
    if(n == 1) {sum2[1] = 1; return;}
    if(sum1[n-1] == 0){
        fibo(n-1);
    }
    if(sum1[n-2] == 0){
        fibo(n-2);
    }
    sum1[n] = sum1[n-1] + sum1[n-2];
    sum2[n] = sum2[n-1] + sum2[n-2];
}

int main()
{
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        fibo(x);
        cout << sum1[x] << " " << sum2[x] << "\n";
    }
    return 0;
}
