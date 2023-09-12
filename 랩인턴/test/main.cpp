#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double one = 1;
    double tmp = 1;
    int cnt = 0;
    for(;;){
        if(one == tmp + pow(2,-cnt)) break;
        cnt++;
    }
    cout << cnt << " " << pow(2,-cnt) << "\n";

    float oone = 1;
    float ttmp = 1;
    cnt = 0;
    for(;;){
        if(oone == ttmp + float(pow(2,-cnt))) break;
        cnt++;
    }
    cout << cnt << " " << pow(2,-cnt) << "\n";
}
