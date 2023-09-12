#include <iostream>
#include <cmath>

using namespace std;

long long p = 1000000007;

long long gap[1000001];
long long sum[1000001];

long long two = 1;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;

    gap[1] = 1;
    gap[2] = 1;
    sum[0] = 0;
    sum[1] = 1;
    sum[2] = 2;

    for(int i=3; i<=1000000; i++){
        two *= 2;
        two %= p;
        gap[i] = (2+two) * gap[i-1];
        gap[i] %= p;

        sum[i] = sum[i-1] + gap[i];
        sum[i] %= p;
    }

    for(int i=0; i<q; i++){
        int x;
        long long a,b,c,Answer;
        cin >> x;
        if(x==1){
            cin >> a >> b >> c;
            if(b > c) swap(b,c);
            Answer = (a*gap[b])%p;
            cout << Answer << "\n";
        }
        else if(x==2){
            cin >> a >> b >> c;
            if(b > c) swap(b,c);
            if(c == 1 || c == 2) c = 1;
            int cnt = 0;
            while(a%2==0){
                cnt++;
                a/=2;
            }

            Answer = (cnt + c-1)%p;
            cout << Answer << "\n";
        }
        else if(x==3){
            cin >> a >> b >> c;
            if(b > c) swap(b,c);
            Answer = sum[c] - sum[b-1];
            if(Answer < 0) Answer += p;
            Answer *= a;
            Answer %= p;
            cout << Answer << "\n";
        }
        else{
            cin >> a >> b;
            Answer = (a*gap[b])%p;
            cout << Answer << "\n";
        }
    }
}
