#include <iostream>

using namespace std;

int a[5001];
int b[5001];
int arr[5001][5001] = {0};

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        b[n+1-i] = a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i] == b[j]) arr[i][j] = arr[i-1][j-1] + 1;
            else arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
        }
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int tmp;
        cin >> tmp;
        int len = arr[tmp-1][n-tmp];
        cout << n - 1 - 2*len << "\n";
    }
}
