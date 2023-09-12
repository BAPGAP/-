#include <iostream>

using namespace std;

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        int l,r;
        cin >> l >> r;
        if(r%2){
            if(l <= (r+1)/2) cout << r/2 << "\n";
            else cout << r%l << "\n";
        }
        else{
            if(l <= r/2+1) cout << r/2-1 << "\n";
            else cout << r%l << "\n";
        }
    }
}
