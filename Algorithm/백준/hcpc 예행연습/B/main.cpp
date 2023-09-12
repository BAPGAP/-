#include <iostream>
#include <cmath>

using namespace std;

struct dot{
    long double x,y,z;
};

dot B;
dot ab,ac;
dot a,b,c;

bool inplane(long double aa,long double bb,long double cc){
    //평면의 방정식 = Bx(x - ax) + By(y - ay) + Bz(z - az) = 0
    long double answer = B.x*(aa - a.x) + B.y*(bb - a.y) + B.z*(cc - a.z);
    if(abs(answer) < 1e-6) return true;
    else return false;
}

int main()
{
    int n;
    cin >> n;
    cin >> a.x >> a.y >> a.z;
    cin >> b.x >> b.y >> b.z;
    cin >> c.x >> c.y >> c.z;


    ab.x = b.x - a.x;
    ab.y = b.y - a.y;
    ab.z = b.z - a.z;

    ac.x = c.x - a.x;
    ac.y = c.y - a.y;
    ac.z = c.z - a.z;

    // ab X ac

    B.x = ab.y * ac.z - ab.z * ac.y;
    B.y = ab.z * ac.x - ab.x * ac.z;
    B.z = ab.x * ac.y - ab.y * ac.x;

    for(int i=0; i<n-3; i++){
        long double j,q,k;
        cin >> j >> q >> k;
        if(!inplane(j,q,k)){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
