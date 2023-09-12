#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n;
        cin >> n;
        if(n%2 == 0){
            for(int i=0; i<(n-1)/2; i++){
                cout << "a";
            }
            cout << "b";
            for(int i=0; i<n/2; i++){
                cout << "a";
            }
            cout << "\n";
        }
        else{
            if(n == 1) cout << "a\n";
            else if(n == 3) cout << "abc\n";
            else{
                for(int i=0; i<n/2; i++){
                    cout << "a";
                }
                cout << "b";
                for(int i=0; i<n/2-1; i++){
                    cout << "a";
                }
                cout << "c\n";
            }
        }
    }
}
