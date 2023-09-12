#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int a[10][10];
int Answer = -1;
int ten[9] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

int main()
{
    int n,m;
    string s;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            a[i][j] = s[j] - '0';
        }
    }

    if(n == 0 || m == 0){
        cout << "-1";
        return 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<)
        }
    }
}
