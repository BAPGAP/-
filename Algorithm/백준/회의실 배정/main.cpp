#include <iostream>

using namespace std;

int a[100001][2];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i][0] >> a[i][1];
        for(int j=i; j>0; j--){
            if(a[j][1] > a[j-1][1]) break;
            else if(a[j][1] == a[j-1][1] && a[j][0] >= a[j-1][0]) break;
            else{
                int t1,t2;
                t1 = a[j][1];
                t2 = a[j][0];
                a[j][1] = a[j-1][1];
                a[j][0] = a[j-1][0];
                a[j-1][1] = t1;
                a[j-1][0] = t2;
            }
        }
    }
    int cnt = 0;
    int tmp = 0;
    for(int i=1; i<=n; i++){
        if(tmp <= a[i][0]){
            cnt++;
            tmp = a[i][1];
        }
    }
    cout << cnt << endl;
}
