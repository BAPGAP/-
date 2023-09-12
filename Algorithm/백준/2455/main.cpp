#include <iostream>

using namespace std;

int a[4][2];

int main()
{
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            cin >> a[i][j];
        }
    }
    int Answer = 0;
    int sum = 0;
    for(int i=0; i<4; i++){
        sum -= a[i][0];
        sum += a[i][1];
        if(Answer < sum) Answer = sum;
    }
    cout << min(Answer,10000);
}
