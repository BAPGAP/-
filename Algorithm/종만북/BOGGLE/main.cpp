#include <iostream>
#include <stack>

using namespace std;

char c[6][6];

int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){

        for(int i=1; i<=5; i++){
            for(int j=1; j<=5; j++){
                cin >> c[i][j];
            }
        }

        int x;
        cin >> x;
        for(int i=0; i<x; i++){
            int check[7][7] = {0};
            string s;
            cin >> s;
            int cnt = 0;
            while(cnt < s.size()){
                stack<pair<int,int>> ss;
                for(int j=1; j<=5; j++){
                    for(int k=1; k<=5; k++){
                        if(c[j][k] == s[cnt]){
                            if(check[j-1][k-1]==cnt||check[j][k-1]==cnt||check[j+1][k-1]==cnt||check[j-1][k]==cnt||check[j+1][k]==cnt||check[j-1][k+1]==cnt||check[j][k+1]==cnt||check[j+1][k+1]==cnt){
                                ss.push({j,k});
                            }
                        }
                    }
                }
                cnt++;
                while(!ss.empty()){
                    check[ss.top().first][ss.top().second] = cnt;
                    ss.pop();
                }
            }
            bool yes = false;
            for(int j=1; j<=5; j++){
                for(int k=1; k<=5; k++){
                    if(check[j][k] == s.size()) yes = true;
                }
            }
            if(yes) cout << s << " " << "YES" << "\n";
            else cout << s << " " << "NO" << "\n";
        }
    }
}
