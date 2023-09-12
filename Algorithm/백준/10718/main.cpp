#include <iostream>

using namespace std;

double a[1001];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        double m;
        cin >> m;
        double sum = 0;
        for(int j=0; j<m; j++){
            cin >> a[j];
            sum += a[j];
        }
        sum /= m;
        double cnt = 0;
        for(int j=0; j<m; j++){
            if(sum < a[j]) cnt++;
        }
        cout << fixed;
        cout.precision(3);
        cout << cnt/m*100 << "%\n";
    }
}
