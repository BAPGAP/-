#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<long long>> bang;
long long n,h_atk;

bool gogo(long long x){
    long long now = x; //현재 체력
    long long atk = h_atk; //현재 공격력
    for(int i=0; i<n; i++){
        if(bang[i][0] == 1){
            long long monster_atk = bang[i][1];
            long long monster_hp = bang[i][2];

            long long bad = now%monster_atk ? now/monster_atk + 1 : now/monster_atk;
            long long good = monster_hp%atk ? monster_hp/atk + 1 : monster_hp/atk;

            if(bad < good) return false;
            else{
                now -= (good-1)*monster_atk;
            }
        }
        else{
            atk += bang[i][1];
            now += bang[i][2];
            if(now > x || now < 0) now = x;
        }
    }
    return true;
}

int main()
{
    cin >> n >> h_atk;
    for(int i=1; i<=n; i++){
        long long a,b,c;
        cin >> a >> b >> c;
        bang.push_back(vector<long long>{a,b,c});
    }
    long long L = 1;
    long long R = LLONG_MAX-100000;
    long long M;
    while(L < R){
        M = (L+R)/2;
        if(gogo(M)){
            R = M;
        }
        else L = M+1;
    }
    M = (L+R)/2;
    cout << M;
}
