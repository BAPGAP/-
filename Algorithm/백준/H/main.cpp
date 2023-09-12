#include <iostream>
#include <cstring>

using namespace std;

int a[2001][2001]={0};
bool visit[2001][2001];
int n,m;
int cnt = 0;

void dfsvisit(int x,int y){
    visit[x][y] = true;
    cnt++;
    if(x-1 > 0 && !visit[x-1][y] && a[x-1][y] >=3) dfsvisit(x-1,y);
    if(x+1 <= n&& !visit[x+1][y] && a[x+1][y] >=3) dfsvisit(x+1,y);
    if(y-1 > 0 && !visit[x][y-1]&& a[x][y-1] >=3) dfsvisit(x,y-1);
    if(y+1 <= m && !visit[x][y+1]&& a[x][y+1] >=3) dfsvisit(x,y+1);
}
int check(int x){ //현재 불은 x
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout << "\n";

    memset(visit,false,sizeof(visit));
    cnt = 0;
    for(int i=1; i<=n; i++){
        bool done = false;
        for(int j=1; j<=m; j++){
            if(a[i][j] >= 3){
                dfsvisit(i,j);
                done = true;
                break;
            }
        }
        if(done) break;
    }


    bool ok = true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] >=3 && !visit[i][j]){
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }
    if(ok) return 0; // ok

    bool impossible = true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == x){
                if(i-1 > 0 && a[i-1][j] ==1) a[i-1][j] = x+1;
                if(i+1 <= n && a[i+1][j] ==1) a[i+1][j] = x+1;
                if(j-1 > 0 && a[i][j-1] ==1) a[i][j-1] = x+1;
                if(j+1 <= m && a[i][j+1] ==1) a[i][j+1] = x+1;
                impossible = false;
            }
        }
    }
    if(impossible) return 0; //impossible

    return 2; //next

}

int main()
{

    int sum = 0;
    cin >> n >> m;
    string s;
    for(int i=1; i<=n; i++){
        cin >> s;
        for(int j=1; j<=m; j++){
            a[i][j] = s[j-1] - '0';
            if(a[i][j] == 0){
                a[i][j] = 3;
                sum++;
            }
        }
    }

    if(sum == 0){
        cout << "0 0";
        return 0;
    }
    for(int i=3; ; i++){
        int tmp = check(i);
        if(tmp == 0){
            cout << i-3 << " " << cnt;
            return 0;
        }
        else if(tmp == 1){
            cout << "0 0";
            return 0;
        }
    }
}
