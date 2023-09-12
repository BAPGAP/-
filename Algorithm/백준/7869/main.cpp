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
    //�� ���� �ȸ�����(and ���Ҷ�)
    if(len >= (C1.r + C2.r)*(C1.r + C2.r)) cout << "0.000";
    //�ѿ��� �ٸ� �ѿ��� �����Ҷ�
    else if(len <= C2.r * C2.r + C1.r * C1.r - 2 * C1.r * C2.r){
        cout << fixed;
        cout.precision(3);
        cout << PI * C1.r * C1.r;
    }
    //�������� ������
    else{
        //������ x��ǥ
        long double x = (C1.r*C1.r - C2.r*C2.r + len) / (2 * sqrt(len));
        //������ y��ǥ�� ���� ��
        long double y_p = sqrt(C1.r*C1.r - x*x);

        //�ﰢ�� ũ��
        long double tri1 = abs(x) * y_p;
        long double tri2 = (sqrt(len) - x) * y_p;
        //1,2�� ��ä�� ����
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
