#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i=0; i<n; i++){
        string x;
        cin >> x;
        int tmp = 1;
        int sum = 0;
        for(int j=x.size()-1; j>=0; j--){
            int y = x[j] - '0';
            if(y == 0 || y == 6) sum += tmp*9;
            else sum += tmp*y;
            tmp *= 10;
        }
        if(sum > 100) sum = 100;
        ans += sum;
    }
    double m = (double)ans/(double)n;
    cout << round(m);
}
