#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char all[16];
int L,C;
bool visit[16] = {0};
char Answer[16];

void solve(int x,int mo,int ja){
    if(x > L){
        if(mo == 0 || ja < 2) return;
        for(int i=1; i<=L; i++){
            cout << Answer[i];
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=C; i++){
        if(x == 1 || Answer[x-1] < all[i]){
            Answer[x] = all[i];
            if(all[i] == 'a' || all[i] == 'e' || all[i] == 'i' || all[i] == 'o' || all[i] == 'u'){
                solve(x+1,mo+1,ja);
            }
            else solve(x+1,mo,ja+1);
        }
    }
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> L >> C;
    for(int i=1; i<=C; i++){
        cin >> all[i];
    }
    sort(all+1,all+C+1);
    solve(1,0,0);
}
