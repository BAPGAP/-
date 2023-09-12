#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a > b) swap(a,b);
        //수의 범위 1 ~ 2(b-a)
        int mx = 2*(b-a);
        if(a > mx || b > mx || c > mx) cout << "-1\n";
        else if(c+b-a > mx && c-(b-a) < 1) cout << "-1\n";
        else{
            if(c+b-a <= mx) cout << c+b-a << "\n";
            else cout << c-b+a << "\n";
        }
    }
}
