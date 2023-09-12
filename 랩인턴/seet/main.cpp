#include <iostream>
#include <cmath>
using namespace std;

int a[8][8] = {0};

int da(int x,int y){
    if(a[x][y] != 0) return a[x][y];
    if(x == y) return a[x][y] = 1;
    if(y == 0) return a[x][y] = pow(2,x);
    return a[x][y] = 2*da(x-1,y) + da(x-1,y-1) * pow(2,x-y);
}

int main()
{
    for(int i=1; i<7; i++){
        for(int j=0; j<i; j++){
            cout << i << " " << j << " " << da(i,j) << "\n";
        }
    }
}
