#include <iostream>

using namespace std;
int y1,m1,d1;
int y2,m2,d2;

int main()
{
    cin >>y1 >> m1 >> d1;
    cin >> y2 >>m2 >>d2;
    int day = 360*(y2-y1)+30*(m2-m1)+d2-d1;
    int m = min(day/30,36);
    int mean = day/360;
    int y = mean * 15;
    for(int i=0; i<mean; i++){
        y += i/2;
    }
    cout << y << " " << m << "\n";
    cout << day << "days";
}
