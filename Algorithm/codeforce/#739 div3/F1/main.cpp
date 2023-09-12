#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        string s;
        int k;
        cin >> s >> k;
        if(k==1){
            int cnt = 0;
            for(int i=1; i<s.size(); i++){
                if(s[i-1] != s[i]) cnt++;
            }
            if(cnt == 0){
                cout << s << "\n";
                continue;
            }

            for(int i=1; i<s.size(); i++){
                if(s[i-1] == s[i]) continue;
                else if(s[i-1] > s[i]){
                    for(int j=0; j<s.size(); j++){
                        s[j] = s[i-1];
                    }
                    break;
                }
                else{
                    s[i-1]++;
                    for(int j=0; j<s.size(); j++){
                        s[j] = s[i-1];
                    }
                    break;
                }
            }
            cout << s << "\n";
        }
        else{
            int c[10] = {0};
            for(int i=0; i<s.size(); i++){
                c[s[i] - '0']++;
            }
            int cnt = 0;
            for(int i=0; i<10; i++){
                if(c[i]) cnt++;
            }
            if(cnt <= 2){
                cout << s << "\n";
                continue;
            }

            for(int i=0; i<10; i++){
                c[i] = 0;
            }
            cnt = 0;
            char f,F;
            for(int i=0; i<s.size(); i++){
                int tmp = s[i] - '0';

                if(c[tmp] == 0) cnt++;
                c[tmp]++;
                if(cnt == 1 && c[tmp] == 1) f = s[i];
                else if(cnt == 2 && c[tmp] == 1) F = s[i];
                else if(cnt == 3){
                    if(f > F) swap(f,F);

                    if(f > s[i] && F > s[i]){
                        for(int j=i; j<s.size(); j++){
                            s[j] = f;
                        }
                    }
                    else if(f < s[i] && F < s[i]){
                        if(s[0] == f){
                            if(c[f - '0'] == 1){
                                s[1] = ++F;
                                for(int j=2; j<s.size(); j++){
                                    s[j] = f;
                                }
                            }
                            else{
                                int x = 0;
                                for(int j=i-1; j>=0; j--){
                                    if(s[j] == F) x++;
                                    else break;
                                }
                                if(c[F - '0'] - x){
                                    for(int j=i-1; j>=0; j--){
                                        if(s[j] == f){
                                            s[j] = F;
                                            for(int k=j+1; k<s.size(); k++){
                                                s[k] = f;
                                            }
                                            break;
                                        }
                                    }
                                }
                                else{
                                    for(int j=0; j<s.size(); j++){
                                        if(s[j] == F){
                                            s[j]++;
                                            for(int k=j+1; k<s.size(); k++){
                                                s[k] = f;
                                            }
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        else{
                            if(c[f - '0'] == 1){
                                for(int j=0; j<s.size(); j++){
                                    if(s[j] == f){
                                        f++;
                                        s[j] = f;
                                        if(F == f) f = '0';
                                        for(int k=j+1; k<s.size(); k++){
                                            s[k] = f;
                                        }
                                        break;
                                    }
                                }
                            }
                            else{
                                for(int j=i-1; j>=0; j--){
                                    if(s[j] == f){
                                        s[j] = F;
                                        for(int k=j+1; k<s.size(); k++){
                                            s[k] = f;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else{
                        s[i] = F;
                        for(int j=i+1; j<s.size(); j++){
                            s[j] = f;
                        }
                    }
                    cout << s << "\n";
                    break;
                }
            }
        }
    }
}

