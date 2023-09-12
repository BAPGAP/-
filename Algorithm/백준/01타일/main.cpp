#include <iostream>

using namespace std;

long long arr[101] = {0};

int main()
{
        int m;
        arr[1] = 1;
        arr[2] = 1;
        arr[3] = 1;
        arr[4] = 2;
        arr[5] = 2;
        cin >> m;
        for(int j=0; j<m; j++){
            int n;
            cin >> n;
            for(int i=6; i<=n; i++){
                if(arr[i] == 0) arr[i] = arr[i-1] + arr[i-5];
            }
            cout << arr[n] << "\n";
        }
}
