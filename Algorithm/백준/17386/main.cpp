#include <iostream>

using namespace std;

bool ispointsame(long long x1,long long y1,long long x2,long long y2){
    if(x1 == x2 && y1 == y2) return true;
    return false;
}

int main()
{
    long long x1,x2,x3,x4;
    long long y1,y2,y3,y4;
    cin >> x1 >> y1 >> x2 >> y2; //L1
    cin >> x3 >> y3 >> x4 >> y4; //L2

    long long L1_1 = x1*y2+x2*y3+x3*y1 - y1*x2-y2*x3-y3*x1;
    if(L1_1 > 0) L1_1 = 1;
    else if(L1_1 < 0) L1_1 = -1;
    else L1_1 = 0;

    long long L1_2 = x1*y2+x2*y4+x4*y1 - y1*x2-y2*x4-y4*x1;
    if(L1_2 > 0) L1_2 = 1;
    else if(L1_2 < 0) L1_2 = -1;
    else L1_2 = 0;

    int L1 = L1_1 * L1_2;

    long long L2_1 = x3*y4+x4*y1+x1*y3 - y3*x4-y4*x1-y1*x3;
    if(L2_1 > 0) L2_1 = 1;
    else if(L2_1 < 0) L2_1 = -1;
    else L2_1 = 0;

    long long L2_2 = x3*y4+x4*y2+x2*y3 - y3*x4-y4*x2-y2*x3;
    if(L2_2 > 0) L2_2 = 1;
    else if(L2_2 < 0) L2_2 = -1;
    else L2_2 = 0;

    int L2 = L2_1 * L2_2;

    bool gogo;

    bool notuch = false;
    if(x1 < x3 && x2 < x3 && x1 < x4 && x2 < x4) notuch = true;
    else if(x1 > x3 && x2 > x3 && x1 > x4 && x2 > x4) notuch = true;
    else if(y1 < y3 && y2 < y3 && y1 < y4 && y2 < y4) notuch = true;
    else if(y1 > y3 && y2 > y3 && y1 > y4 && y2 > y4) notuch = true;

    //선분이 겹치지않고 기울기가 같을때
    if((y2-y1)*(x4-x3) == (y4-y3)*(x2-x1) && notuch) gogo = false;
    else if(L1 <= 0 && L2 <= 0) gogo = true;
    else gogo = false;

    if(!gogo) cout << "0";
    else{
        cout << "1\n";
        if(x1==x2&&x2==x3&&x3==x4&&y1==y2&&y2==y3&&y3==y4){
            cout << x1 << " " << y1;
        }
        //기울기가 같으면?
        else if((y2-y1)*(x4-x3) == (y4-y3)*(x2-x1)){
            if(ispointsame(x1,y1,x3,y3) && !ispointsame(x2,y2,x4,y4)){
                if((x1 - x2)*(x1 - x4) <= 0 && (y1 - y2)*(y1 - y4) <= 0){
                    cout << x1 << " " << y1;
                }
            }
            else if(ispointsame(x1,y1,x4,y4) && !ispointsame(x2,y2,x3,y3)){
                if((x1 - x2)*(x1 - x3) <= 0 && (y1 - y2)*(y1 - y3) <= 0){
                    cout << x1 << " " << y1;
                }
            }
            else if(ispointsame(x2,y2,x3,y3) && !ispointsame(x1,y1,x4,y4)){
                if((x2 - x1)*(x2 - x4) <= 0 && (y2 - y1)*(y2 - y4) <= 0){
                    cout << x2 << " " << y2;
                }
            }
            else if(ispointsame(x2,y2,x4,y4) && !ispointsame(x1,y1,x3,y3)){
                if((x2 - x1)*(x2 - x3) <= 0 && (y2 - y1)*(y2 - y3) <= 0){
                    cout << x2 << " " << y2;
                }
            }
        }
        //기울기가 달라 교점이 있음
        else{
            long double m1,m2;
            if(x1 != x2) m1 = (long double)(y2-y1)/(x2-x1);
            if(x3 != x4) m2 = (long double)(y4-y3)/(x4-x3);

            if(x1 == x2){
                cout << x1 << " ";
                long double Answer = m2*(x1 - x3) + (long double)y3;
                cout << fixed;
                cout.precision(16);
                cout << Answer;
            }
            else if(x3 == x4){
                cout << x3 << " ";
                long double Answer = m1*(x3 - x1) + (long double)y1;
                cout << fixed;
                cout.precision(16);
                cout << Answer;
            }
            else{
                long double Answer_x = (m1*x1-m2*x3-y1+y3)/(m1-m2);
                long double Answer_y = m1*(Answer_x - x1) + y1;
                cout << fixed;
                cout.precision(16);
                cout << Answer_x << " " << Answer_y;
            }
        }
    }
}
