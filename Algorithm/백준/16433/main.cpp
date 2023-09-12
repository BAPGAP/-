#include <iostream>

using namespace std;

int main()
{
    int n,r,c;
    cin >> n >> r >> c;
    int tmp = (r+c)%2;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(tmp == (i+j)%2){
                cout << "v";
            }
            else cout << ".";
        }
        cout << "\n";
    }
}
