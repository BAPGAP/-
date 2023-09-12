#include <iostream>

using namespace std;

int main()
{
    int e,s,m;
    cin >> e >> s >> m;
    int Answer = (28*19*13*e + 15*19*17*s + 15*28*10*m)%(15*28*19);
    if(Answer == 0) Answer = 15*28*19;
    cout << Answer;
}
