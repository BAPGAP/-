#include <iostream>

using namespace std;

int arr[3][1001];

int mn(int a,int b){
    if(a>b) return b;
    else return a;
}
int main()
{
    int n;
    cin >> n;
    int x,y,z;
    cin >> x >> y >> z;
    arr[0][1] = x;
    arr[1][1] = y;
    arr[2][1] = z;
    for(int i=2; i<=n; i++){
        cin >> x >> y >> z;
        arr[0][i] = mn(arr[1][i-1], arr[2][i-1]) + x;
        arr[1][i] = mn(arr[2][i-1], arr[0][i-1]) + y;
        arr[2][i] = mn(arr[1][i-1], arr[0][i-1]) + z;
    }
    cout << mn(mn(arr[0][n],arr[1][n]),arr[2][n]) << endl;
}
