#include <iostream>

using namespace std;

int tmp = 1e9;
int two[50];
int cnt = 0;
int gap = 2;

int main()
{
    while(gap < tmp){
        two[cnt] = gap;
        cnt++;
        gap *= 2;
    }
    int T;
    cin >> T;
    while(T--){
        int k;
        cin >> k;
        bool go = true;
        for(int i=0; i<cnt; i++){
            if(two[i] == k) go = false;
        }
        if(go) cout << "Gazua\n";
        else cout << "GoHanGang\n";
    }
}
