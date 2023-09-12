#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    int answer = 0;
    int next = n*m - 1;
    int D_old = abs(n - m);
    while(1){
        if(next == 0) break;
        int D_new;
        int flag = 0;
        for(int i=1; i*i<=next; i++){
            if(next % i) continue;
            n = i;
            m = next/i;
            D_new = abs(n - m);
            if(abs(D_old - D_new) <= k){
                flag = 1;
                answer++;
                break;
            }
        }
        if(flag == 0) break;
        next--;
    }
    cout << answer;
}
