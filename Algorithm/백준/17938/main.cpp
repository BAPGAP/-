#include <iostream>

using namespace std;

int main()
{
    long long n,p,t;
    cin >> n >> p >> t;
    long long cnt = 0;
    int Plus;
    bool ok = true;
    while(ok){
        for(long long i=1; i<=2*n; i++){
            if(t == 1){
                Plus = i;
                ok = false;
                break;
            }
            else{
                t--;
                cnt += i;
                cnt %= 2*n;
            }
        }
        if(!ok) break;
        for(long long i=2*n-1; i>1; i--){
            if(t == 1){
                Plus = i;
                ok = false;
                break;
            }
            else{
                t--;
                cnt += i;
                cnt %= 2*n;
            }
        }
        if(!ok) break;
    }
    cnt %= 2*n;
    //이친구부터 Plus까지
    for(int i=1; i<=Plus; i++){
        if((i+cnt)%(2*n) == (2*p) % (2*n) || (i+cnt)%(2*n) == (2*p - 1)%(2*n)){
            cout << "Dehet YeonJwaJe ^~^";
            return 0;
        }
    }
    cout << "Hing...NoJam";
    return 0;
}
