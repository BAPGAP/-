#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alpha[27] = {0};

int main()
{
    string s[502];
    int n,m,k;
    int sum = 0;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    int total = n*m/k;
    total /= k;

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            fill(alpha, alpha+26,0);
            for(int a=0; a<n/k; a++){
                for(int b=0; b<m/k; b++){
                    int num = s[a*k+i][b*k+j] - 'A';
                    alpha[num]++;
                }
            }
            int mx = -9999999;
            int idx = 0;
            for(int a=0; a<26; a++){
                if(mx < alpha[a]){
                    mx = alpha[a];
                    idx = a;
                }
            }
            sum += total - mx;
            for(int a=0; a<n/k; a++){
                for(int b=0; b<m/k; b++){
                    s[a*k+i][b*k+j] = char(int('A') + idx);
                }
            }
        }
    }
    cout << sum << "\n";
    for(int i=0; i<n; i++){
        cout << s[i] << "\n";
    }
}
