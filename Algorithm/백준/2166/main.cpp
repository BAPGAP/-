#include <iostream>
#include <cmath>

using namespace std;

struct point{
    long long x,y;
};

point P[10001];

long long triangle(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3){
    return (x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3);
}


int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> P[i].x >> P[i].y;
    }
    long long Answer = 0;
    for(int i=3; i<=n; i++){
        Answer += triangle(P[1].x,P[1].y,P[i-1].x,P[i-1].y,P[i].x,P[i].y);
    }
    Answer = abs(Answer);
    cout << fixed;
    cout.precision(1);
    cout << (long double)Answer/2;
}
