#include <iostream>

using namespace std;

long long h;
long long x;
long long P = 1000000007;
long long Answer = 0;
long long tmp;
long long big;

int main()
{
    cin >> h >> x;
    big = x;

    for(int i=1; i<=h; i++){
        cin >> tmp;
        Answer += (big * tmp) % P;
        Answer = Answer % P;
        big = (x * big) % P;
    }
    cout << Answer << endl;
    return 0;
}
