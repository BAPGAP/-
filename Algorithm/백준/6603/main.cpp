#include <iostream>

using namespace std;

int a[14];
int Answer[7];
bool visit[14] = {0};

void solve(int x,int n){
    if(x == 7){
        for(int i=1; i<=6; i++){
            cout << Answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++){
        if(!visit[i] && a[i] > Answer[x-1]){
            visit[i] = true;
            Answer[x] = a[i];
            solve(x+1,n);
            visit[i] = false;
        }
    }
}

int main()
{
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        solve(1,n);
        cout << "\n";
    }
}
