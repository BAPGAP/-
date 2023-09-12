#include <iostream>
#include <string>

using namespace std;

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        int n;
        string s;
        cin >> n >> s;
        if(n == 1){
            cout << "1\n" << s << "\n";
            continue;
        }

        int cnt[10] = {0};
        for(int i=0; i<s.size(); i++){
            int tmp = s[i] - '0';
            cnt[tmp]++;
        }

        if(cnt[1] > 0){
            cout << "1\n1\n";
            continue;
        }
        if(cnt[9] > 0){
            cout << "1\n9\n";
            continue;
        }
        if(cnt[4] > 0){
            cout << "1\n4\n";
            continue;
        }
        if(cnt[6] > 0){
            cout << "1\n6\n";
            continue;
        }
        if(cnt[8] > 0){
            cout << "1\n8\n";
            continue;
        }

        bool ok = false;
        for(int i=1; i<s.size(); i++){
            int tmp = s[i] - '0';
            if(tmp%2 == 0 || tmp == 5){
                cout << "2\n" << s[i-1] << s[i] << "\n";
                ok = true;
                break;
            }
        }
        if(ok) continue;

        if(s[0] == '2' && cnt[7] > 0){
            cout << "2\n27\n";
            continue;
        }
        if(s[0] == '5' && cnt[7] > 0){
            cout << "2\n57\n";
            continue;
        }
        if(cnt[3] > 1){
            cout << "2\n33\n";
            continue;
        }
        if(cnt[7] > 1){
            cout << "2\n77\n";
            continue;
        }
    }
}
