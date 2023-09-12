#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,m;
    string x;
    string s;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m;
        int a[31]={0};
        string b[31];
        int cnts = 0;

        for(int j=0; j<m; j++){
            cin >> x >> s;
            for(int k=0; k<=cnts; k++){
                if(b[k] == s) {a[k]++; break;}
                if(k == cnts){
                    b[cnts] = s;
                    a[cnts]++;
                    cnts++;
                    break;
                }
            }
        }
        int sum = 1;
        for(int i=0; i<cnts; i++){
            sum *=  (a[i] + 1);
        }
        cout << sum-1 << "\n";
    }
}
