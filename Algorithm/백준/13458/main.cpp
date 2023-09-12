#include <iostream>

using namespace std;

long long a[1000001];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int b,c;
    cin >> b >> c;
    long long Answer = 0;
    for(int i=1; i<=n; i++){
        if(a[i] <= b) Answer++;
        else{
            Answer += 1 + (a[i] - b)/c;
            if((a[i] - b) % c != 0) Answer++;
        }
    }
    cout << Answer << "\n";
}
