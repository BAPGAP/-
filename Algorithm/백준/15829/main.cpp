#include <iostream>

using namespace std;

int main()
{
    long long r = 1;
    long long M = 1234567891;
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long Answer = 0;
    for(int i=0; i<n; i++){
        Answer += (s[i] - 'a' + 1) * r;
        Answer %= M;
        r *= 31;
        r %= M;
    }
    cout << Answer;
}
