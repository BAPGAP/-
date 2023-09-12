#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin >> m;
    string s;
    int bitmask = 0;
    for(int i=0; i<m; i++){
        cin >> s;
        if(s == "all"){
            bitmask = (1 << 21) - 1;
        }
        else if(s == "add"){
            int x;
            cin >> x;
            x--;
            bitmask |= (1 << x);
        }
        else if(s == "check"){
            int x;
            cin >> x;
            x--;
            if(bitmask & (1 << x)) cout << "1\n";
            else cout << "0\n";
        }
        else if(s == "remove"){
            int x;
            cin >> x;
            x--;
            bitmask &= ~(1 << x);
        }
        else if(s == "empty"){
            bitmask = 0;
        }
        else if(s == "toggle"){
            int x;
            cin >> x;
            x--;
            bitmask ^= (1 << x);
        }
    }
}
