#include <iostream>

using namespace std;

long long a,b,c;

long long n_x(int n,int x){
    long long x1;
    long long x2;
    long long x3;
    long long x4;
    if(x == 0) {
            return 1;
    }
    x1 = n%c;
    if(x == 1){
        return x1;
    }
    x2 = (n*x1)%c;
    if(x == 2) {

        return x2;
    }

    x3 = (n*x2)%c;
    if(x == 3) { return x3;}
    x4 = (n*x3)%c;
    if(x == 4) { return x4;}

    if(x%4==0) { return (n_x(x4,x/4))%c;}
    else if(x%4==1) { return (n_x(x4,x/4) * x1)%c;}
    else if(x%4==2) { return (n_x(x4,x/4) * x2)%c;}
    else if(x%4==3) { return (n_x(x4,x/4) * x3)%c;}
}


int main()
{
    cin >> a >> b >> c;
    a = a%c;
    //if(c-a < a) a = a-c;
    //long long tmp = n_x(a,b);
    //if(tmp < 0) cout << tmp + c;
    //else cout << tmp;
    cout << n_x(a,b);
}
