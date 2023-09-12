#include <iostream>

using namespace std;

int a[1000001]={0},n;

int mx(int a,int b){
    if(a>b) return b;
    return a;
}

int main()
{
    cin >> n;
    a[2] = 1;
    a[3] = 1;
    for(int i=4; i<=n; i++){
        if(i%3 == 0 && i%2 == 0){
            a[i] = mx(mx(a[i/3],a[i/2]),a[i-1]) + 1;
        }
        else if(i%3 == 0){
            a[i] = mx(a[i/3],a[i-1]) + 1;
        }
        else if(i%2 == 0){
            a[i] = mx(a[i/2],a[i-1]) + 1;
        }
        else a[i] = a[i-1] + 1;
    }
    cout << a[n] << endl;
    return 0;
}
