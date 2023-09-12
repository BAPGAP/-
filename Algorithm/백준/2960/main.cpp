#include <iostream>

using namespace std;

int p[1001] = {0};
int cnt = 0;

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i=2; i<=n; i++){
        if(p[i] == 0){
            cnt++;
            if(cnt == k){
                cout << i;
                return 0;
            }
            for(int j=i*i; j<=n; j+=i){
                if(p[j] == 1) continue;
                p[j] = 1;
                cnt++;
                if(cnt == k){
                    cout << j;
                    return 0;
                }
            }
        }
    }
}
