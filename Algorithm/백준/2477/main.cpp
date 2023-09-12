#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vv;
int cnt[5] = {0};
int ok[6] = {0};
int main()
{
    int k;
    cin >> k;
    for(int i=1; i<=6; i++){
        int x,y;
        cin >> x >> y;
        cnt[x]++;
        vv.push_back(vector<int>{x,y});
    }
    int S = 1;
    int L = 1;
    for(int i=0; i<6; i++){
        if(cnt[vv[i][0]] == 1){
            L *= vv[i][1];
            ok[(i+5)%6] = 1;
            ok[((i+1)%6)] = 1;
        }
    }
    for(int i=0; i<6; i++){
        if(ok[i] == 0){
            S *= vv[i][1];
        }
    }
    cout << k*(L-S);
}
