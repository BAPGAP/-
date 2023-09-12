#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n,m;
        cin >> n >> m;
        m = m+1;
        int cnt = 30;
        int Answer = 0;
        while(cnt >= 0){
            if(m & (1 << cnt)){
                if(n & (1 << cnt)){}
                else Answer += (1 << cnt);
            }
            else{
                if(n & (1 << cnt)) break;
            }
            cnt--;
        }
        cout << Answer << "\n";
    }
}
