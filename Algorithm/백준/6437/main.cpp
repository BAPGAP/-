#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        int cnt = 0;
        for(int a=1; a<n; a++){
            for(int b=a+1; b<n; b++){
                if((a*a+b*b+m)%(a*b) == 0) cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
