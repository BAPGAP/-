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
        double A,B,D;
        char c;
        cin >> A >> B >> c >> D;
        char ch = c;
        int a = 1000 * A;
        int b = 1000 * B;
        int d = 1000 * D;
        int mn = 6;
        if(ch == 'A'){
            // a up
            int cnt = 0;
            int tmp = a;

            while(cnt < 6){
                if(tmp == d) break;
                tmp += 20;
                if(tmp > 146000) tmp = 144000;
                cnt++;
            }
            mn = min(mn,cnt);
            // a down
            cnt = 0;
            tmp = a;
            while(cnt < 6){
                if(tmp == d) break;
                tmp -= 20;
                if(tmp < 144000) tmp = 146000;
                cnt++;
            }
            mn = min(mn,cnt);

            // b up
            cnt = 1;
            tmp = b;

            while(cnt < 6){
                if(tmp == d) break;
                tmp += 20;
                if(tmp > 146000) tmp = 144000;
                cnt++;
            }
            mn = min(mn,cnt);
            // b down
            cnt = 1;
            tmp = b;
            while(cnt < 6){
                if(tmp == d) break;
                tmp -= 20;
                if(tmp < 144000) tmp = 146000;
                cnt++;
            }
            mn = min(mn,cnt);
        }
        else{
            // a up
            int cnt = 1;
            double tmp = a;

            while(cnt < 6){
                if(tmp == d) break;
                tmp += 20;
                if(tmp > 146000) tmp = 144000;
                cnt++;
            }
            mn = min(mn,cnt);
            // a down
            cnt = 1;
            tmp = a;
            while(cnt < 6){
                if(tmp == d) break;
                tmp -= 20;
                if(tmp < 144000) tmp = 146000;
                cnt++;
            }
            mn = min(mn,cnt);

            // b up
            cnt = 0;
            tmp = b;

            while(cnt < 6){
                if(tmp == d) break;
                tmp += 20;
                if(tmp > 146000) tmp = 144000;
                cnt++;
            }
            mn = min(mn,cnt);
            // b down
            cnt = 0;
            tmp = b;
            while(cnt < 6){
                if(tmp == d) break;
                tmp -= 20;
                if(tmp < 144000) tmp = 146000;
                cnt++;
            }
            mn = min(mn,cnt);
        }
        cout << mn << "\n";
    }
}
