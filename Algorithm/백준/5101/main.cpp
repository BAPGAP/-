#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    char m1,m2,t1,t2;
    cin >> m1 >> m2 >> t1 >> t2;
    if(m1 == m2 && m1 == 'S' && (t1 == 'R' || t2 == 'R')) cout << "TK";
    else if(m1 == m2 && m1 == 'R' && (t1 == 'P' || t2 == 'P')) cout << "TK";
    else if(m1 == m2 && m1 == 'P' && (t1 == 'S' || t2 == 'S')) cout << "TK";
    else if(t1 == t2 && t1 == 'S' && (m1 == 'R' || m2 == 'R')) cout << "MS";
    else if(t1 == t2 && t1 == 'R' && (m1 == 'P' || m2 == 'P')) cout << "MS";
    else if(t1 == t2 && t1 == 'P' && (m1 == 'S' || m2 == 'S')) cout << "MS";
    else cout << "?";
}
