#include <iostream>
#include <vector>

using namespace std;

int in[10002];

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            if(x) in[i] = 1;
            else in[i] = 0;
        }
        if(in[1] == 1){
            cout << n+1 << " ";
            for(int i=1; i<=n; i++){
                cout << i << " ";
            }
            cout << "\n";
            continue;
        }
        if(in[n] == 0){
            for(int i=1; i<=n; i++){
                cout << i << " ";
            }
            cout << n+1 << " ";
            cout << "\n";
            continue;
        }

        bool ok = false;
        int pos;
        for(int i=1; i<n; i++){
            //i,i+1이 i->n+1->i+1이어야 길이 있는거임
            if(in[i] == 0 && in[i+1] == 1){
                ok = true;
                pos = i;
                break;
            }
        }
        if(ok){
            for(int i=1; i<=pos; i++){
                cout << i << " ";
            }
            cout << n+1 << " ";
            for(int i=pos+1; i<=n; i++){
                cout << i << " ";
            }
            cout << "\n";
        }
        else cout << "-1\n";
    }
}
