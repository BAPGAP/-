#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int tmp = sqrt(n-1);
        tmp += 1;
        int first = (tmp-1)*(tmp-1) + 1;
        //(1,tmp) = first
        int len = n - first;
        if(len < tmp) cout << len+1 << " " << tmp << "\n";
        else{
            len = tmp*tmp - n;
            cout << tmp << " " << len+1 << "\n";
        }
    }
}
