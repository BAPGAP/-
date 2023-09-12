#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int h=0,m=0,s=0;
    for(int i=0; i<n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        h += a;
        m += b;
        s += c;
    }
    m += s/60;
    s = s%60;
    h += m/60;
    m = m%60;
    cout << h << " " << m << " " << s;
}
