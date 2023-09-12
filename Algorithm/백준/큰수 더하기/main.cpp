#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    int c[10001];
    cin >> a >> b;
    int s=0;
    int a_= a.size()-1;
    int b_= b.size()-1;
    int cnt = 0;
    while(1){
        if(a_ < 0 || b_ < 0){
            if(a_ == b_ && s == 1){
                c[cnt] = 1;
                cnt++;
            }
            break;
        }
        int n1 = a[a_] - '0';
        int n2 = b[b_] - '0';
        if(n1 + n2 + s >= 10){
            c[cnt] = n1 + n2 + s - 10;
            s = 1;
        }
        else{
            c[cnt] = n1 + n2 + s;
            s = 0;
        }
        a_--;
        b_--;
        cnt++;
    }
    if(a_ < 0 && b_ >= 0){
        while(1){
            if(b_ < 0){
                if(s == 1){
                    c[cnt] = 1;
                    cnt++;
                }
                break;
            }
            int n3 = b[b_] - '0';
            if(n3 + s >= 10){
                c[cnt] = n3 + s - 10;
                s = 1;
            }
            else{
                c[cnt] = n3 + s;
                s = 0;
            }
            b_--;
            cnt++;
        }
    }
    else if(b_ < 0 && a_ >= 0){
        while(1){
            if(a_ < 0){
                if(s == 1){
                    c[cnt] = 1;
                    cnt++;
                }
                break;
            }
            int n4 = a[a_] - '0';
            if(n4 + s >= 10){
                c[cnt] = n4 + s - 10;
                s = 1;
            }
            else{
                c[cnt] = n4 + s;
                s = 0;
            }
            a_--;
            cnt++;
        }
    }

    for(int i=cnt-1; i>=0; i--){
        cout << c[i];
    }
    return 0;
}
