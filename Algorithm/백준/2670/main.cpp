#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double Answer = 0;
    double gop = 1;
    for(int i=0; i<n; i++){
        double x;
        cin >> x;
        gop *= x;
        if(gop > Answer) Answer = gop;
        if(gop < 1) gop = 1;
    }
    cout << fixed;
    cout.precision(3);
    cout << Answer;
}
