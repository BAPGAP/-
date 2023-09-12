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
        string s;
        cin >> s;
        long long first = stoll(s);
        int cnt = 0;
        while(1){
            if(first%10 == 0){
                first /= 10;
                cnt++;
            }
            else break;
        }
        string zero = "";
        for(int i=0; i<cnt; i++){
            zero += "0";
        }

        long long tmp = first;
        bool f = false;
        bool b = false;
        string ff;
        string bb;
        bool isodd = false;

        while(!f || !b){
            string gogo = to_string(tmp);
            int sum = 0;
            for(int i=0; i<gogo.size(); i++){
                sum += gogo[i] - '0';
            }
            if(sum%2){
                isodd = true;
                cout << gogo + zero << "\n";
                break;
            }

            if(!f && gogo[0] >= '5'){
                f = true;
                ff = gogo;
            }
            if(!b && gogo.size() > 1 && gogo[gogo.size()-2] != '9' && gogo[gogo.size()-1] >= '5'){
                b = true;
                bb = gogo;
            }
            tmp += first;
        }
        if(isodd) continue;
        //bb ff
        long long answer = stoll(bb) * (long long)pow(10,ff.size()-1) + stoll(ff);
        string A = to_string(answer);
        cout << A + zero << "\n";
    }
}
