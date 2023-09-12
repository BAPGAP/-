#include <iostream>
#include <cstring>
using namespace std;
int a[2][200011];
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        memset(a,0,sizeof a);
        int n;
        cin >> n;
        string s;
        cin >> s;
        for(int i=0; i<n; i++){
            a[0][i] = s[i] - '0';
        }
        cin >> s;
        for(int i=0; i<n; i++){
            a[1][i] = s[i] - '0';
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(a[1][i] == 1 && a[0][i] == 0){
                cnt++;
                a[1][i] = 0;
            }
        }
        for(int i=0; i<n; i++){
            if(a[0][i] == 1){
                int line = 0;
                int tmp = i;
                while(tmp < n){
                    if(a[0][tmp] == 1 && a[1][tmp+1] == 1){
                        a[0][tmp] = 0;
                        a[1][tmp+1] = 0;
                        line++;
                        tmp += 2;
                    }
                    else if(a[0][tmp] == 1){
                        a[0][tmp] = 0;
                        break;
                    }
                    else break;
                }
                cnt += line;
            }
            if(a[1][i] == 1){
                int line = 0;
                int tmp = i;
                while(tmp < n){
                    if(a[1][tmp] == 1 && a[0][tmp+1] == 1){
                        a[1][tmp] = 0;
                        a[0][tmp+1] = 0;
                        line++;
                        tmp += 2;
                    }
                    else if(a[1][tmp] == 1){
                        a[1][tmp] = 0;
                        break;
                    }
                    else break;
                }
                cnt += line;
            }
        }
        cout << cnt << "\n";
    }
}
