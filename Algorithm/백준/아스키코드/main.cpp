#include <iostream>

using namespace std;

int main()
{
    int n;
    int s = 0;
    char c;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> c;
        int d = c - '0';
        s += d;
    }
    cout << s << endl;
    return 0;
}
