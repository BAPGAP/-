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

    cout << "double\n";
    cout << "1 = 1 + 2^-" << cnt << "\n";
    cout << "epsilon : " << pow(2,-cnt+1) << "\n";
    cout << "neg epsilon : " << pow(2,-cnt) << "\n";
    cout << "\n\n";
    float oone = 1;
    float ttmp = 1;
    cnt = 0;
    for(;;){
        if(oone == ttmp + float(pow(2,-cnt))) break;
        cnt++;
    }
    cout << "float\n";
    cout << "1 = 1 + 2^-" << cnt << "\n";
    cout << "epsilon : " << pow(2,-cnt+1) << "\n";
    cout << "neg epsilon : " << pow(2,-cnt) << "\n";
}
