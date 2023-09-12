#include <iostream>

using namespace std;

int w,h,x,y,p;

bool isinside(int a,int b){
    if((a - x)*(a - x) + (b - y - h/2)*(b - y - h/2) <= h*h/4) return true; //left O
    if((a - x - w)*(a - x - w) + (b - y - h/2)*(b - y - h/2) <= h*h/4) return true;
    if(x <= a && a <= x+w){
        if(y <= b && b <= y + h) return true;
    }
    return false;
}

int main()
{
    cin >> w >> h >> x >> y >> p;
    int cnt = 0;
    for(int i=0; i<p; i++){
        int a,b;
        cin >> a >> b;
        if(isinside(a,b)) cnt++;
    }
    cout << cnt;
}
