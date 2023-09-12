#include <iostream>
#include <cmath>

using namespace std;

int abs(int x){
    if(x < 0) return -x;
    else return x;
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int dold = abs(m-n);
    int total = n*m;
    int cnt = 0;
    if(total == 1) cout << "0";
    else{
        while(total > 1){
            total--;
            int tmp;
            for(int i=sqrt(total); i>=1; i--){
                if(total%i == 0){
                    tmp = i;
                    break;
                }
            }
            if(abs(abs(tmp-total/tmp) - dold) > k) break;
            cnt++;
        }
        cout << cnt;
    }
}
