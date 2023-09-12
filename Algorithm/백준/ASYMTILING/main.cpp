#include <iostream>

using namespace std;

long long p = 1e9 + 7;

long long all[101];
long long sys[101];

int main()
{
    int T;
    cin >> T;

    all[1] = 1;
    all[2] = 2;

    for(int i=3; i<=100; i++){
        all[i] = (all[i-1] + all[i-2])%p;
    }

    sys[1] = 1;
    sys[2] = 2;
    sys[3] = 1;
    sys[4] = 3;

    for(int i=5; i<=100; i++){
        sys[i] = (sys[i-2] + sys[i-4])%p;
    }


    while(T--){
        int n;
        cin >> n;
        cout << (all[n] - sys[n] + p) % p << "\n";
    }
}
