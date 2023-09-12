#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int sixteen = 1;
    int sum = 0;
    for(int i=s.size()-1; i>=0; i--){
        if('A' <= s[i] && s[i] <= 'F') sum += ((s[i] - 'A') + 10) * sixteen;
        else sum += (s[i] - '0') * sixteen;
        sixteen *= 16;
    }
    cout << sum;
}
