#include <iostream>

using namespace std;

int l[1000001];

void init(int a,int Size){
    int L = 1;
    int R = Size;
    while(1){
        if(L == R){
            l[L] = a;
            return;
        }
        int M = (L+R)/2;
        if(a <= l[M]){
            R = M;
        }
        else{
            L = M+1;
        }
    }
}

int main()
{
    int n;
    int a;
    cin >> n >> a;

    l[1] = a;

    int Size = 1;

    for(int i=2; i<=n; i++){
        cin >> a;
        if(a > l[Size]){
            Size++;
            l[Size] = a;
        }
        else{
            init(a,Size);
        }
        /*for(int i=1;i<=Size; i++){
            cout << l[i] << " ";
        }
        cout << "\n"; */
    }
    cout << Size;
}
