#include <iostream>

using namespace std;

int score[6][4];

int main()
{
    int num;
    int sum = 0;
    for(int i=1; i<=5; i++){
        int tmp = 0;
        for(int j=0; j<4; j++){
            cin >> score[i][j];
            tmp += score[i][j];
        }
        if(sum < tmp){
            sum = tmp;
            num = i;
        }
    }
    cout << num << " ";
    cout << sum;
}
