#include <iostream>

using namespace std;

int sum = 0;
int ed;

bool isyoon(int year){
    if(year%400 == 0) return true;
    else if(year%100==0) return false;
    else if(year%4==0) return true;
    else return false;
}

int main()
{
    //2019/1/4 ±Ý¿äÀÏ
    int n;
    cin >> ed;

    int y=2019,m=1,d=4;

    while(1){
        d += 7;
        if(d == 13) sum++;

        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
            if(d>31){
                m++;
                d -= 31;
            }
        }
        else if(m==4 || m == 6 ||m==9 || m==11){
            if(d>30){
                m++;
                d -= 30;
            }
        }
        else{
            if(isyoon(y)){
                if(d>29){
                    m++;
                    d -= 29;
                }
            }
            else{
                if(d>28){
                    m++;
                    d -= 28;
                }
            }
        }

        if(m > 12){
            y++;
            m = 1;
        }
        if(y > ed) break;
    }
    cout << sum;
}
