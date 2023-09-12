#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long double x,y,d,t;
    cin >> x >> y >> d >> t;
    long double len = sqrt(x*x + y*y);
    long double Answer;
    int jump = len/d;

    if(len >= d){
        Answer = min({jump*(t-d)+len,(jump+1)*t,len});
    }
    else{
        Answer = min({t+d-len,2*t,len});
    }

    cout << fixed;
    cout.precision(13);
    cout << Answer;
}
