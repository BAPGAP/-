#include <iostream>
#include <cmath>

using namespace std;

long double PI = 3.14159265358979;

struct circle{
    long double x,y,r;
};

int main()
{
    circle C1,C2;
    cin >> C1.x >> C1.y >> C1.r >> C2.x >> C2.y >> C2.r;
    if(C1.r > C2.r) swap(C1,C2);

    long double len = (C1.x - C2.x)*(C1.x - C2.x) + (C1.y - C2.y)*(C1.y - C2.y);
    //두 원이 안만날때(and 접할때)
    if(len >= (C1.r + C2.r)*(C1.r + C2.r)) cout << "0.000";
    //한원이 다른 한원을 포함할때
    else if(len <= C2.r * C2.r + C1.r * C1.r - 2 * C1.r * C2.r){
        cout << fixed;
        cout.precision(3);
        cout << PI * C1.r * C1.r;
    }
    //두점에서 만날때
    else{
        //교점의 x좌표
        long double x = (C1.r*C1.r - C2.r*C2.r + len) / (2 * sqrt(len));
        //교점의 y좌표중 양의 값
        long double y_p = sqrt(C1.r*C1.r - x*x);

        //삼각형 크기
        long double tri1 = abs(x) * y_p;
        long double tri2 = (sqrt(len) - x) * y_p;
        //1,2번 부채꼴 넓이
        long double fan1,fan2;
        long double Answer = 0;

        if(x < 0){
            fan1 = (PI - asin(y_p/C1.r)) * C1.r * C1.r;
            Answer += fan1 + tri1;
        }
        else{
            fan1 = asin(y_p/C1.r) * C1.r * C1.r;
            Answer += fan1 - tri1;
        }
        fan2 = asin(y_p/C2.r) * C2.r * C2.r;
        Answer += fan2 - tri2;

        cout << fixed;
        cout.precision(3);
        cout << Answer;
    }
}
