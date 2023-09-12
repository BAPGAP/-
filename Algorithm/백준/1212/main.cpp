#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << "*";
        }
        cout << "\n";
    }
    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout << "*";
        }
        cout << "\n";
    }
}
