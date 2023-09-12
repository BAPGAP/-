#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    while(1){
        int h1,m1;
        int h2,m2;
        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;

        int start = 60*h1 + m1;
        int ed = start + 60*h2 + m2;
        int day = ed/(24*60);
        ed -= day * 24 * 60;

        printf("%02d:%02d",ed/60,ed%60);
        if(day != 0) cout << " +" << day;
        cout << "\n";
    }
}
