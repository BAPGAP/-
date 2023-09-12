#include <iostream>

#include <cmath>

using namespace std;



int arr[10][10] = {0};



int dp(int a,int b){

    if(arr[a][b] != 0) return arr[a][b];

    if(a == b) return arr[a][b] = 1;

    if(b == 0) return arr[a][b] = pow(2,a);

    return arr[a][b] = 2*dp(a-1,b) + dp(a-1,b-1)*pow(2,a-b);

}



int main()

{

    for(int i=1; i<10; i++){

        for(int j=0; j<i; j++){

            cout << pow(2,i) << " " << pow(2,j) << " " << dp(i,j) << "\n";

        }

    }

}
