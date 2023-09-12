#include <iostream>
#include <queue>

using namespace std;

int one[103][103] = {0};
int two[103][103] = {0};
int thr[103][103] = {0};

queue<pair<int,int>> q;

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=m; j++){
            one[i][j] = s[j-1] - '0';
            two[i][j] = one[i][j];
            thr[i][j] = one[i][j];
        }
    }
    int x,y;
    cin >> x >> y;
    one[x][y] = 2;
    q.push({x,y});
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        int tmp = one[a][b];
        q.pop();
        if(a>1 && one[a-1][b] == 0){
            one[a-1][b] = tmp+1;
            q.push({a-1,b});
        }
        if(a<n && one[a+1][b] == 0){
            one[a+1][b] = tmp+1;
            q.push({a+1,b});
        }
        if(b>1 && one[a][b-1] == 0){
            one[a][b-1] = tmp+1;
            q.push({a,b-1});
        }
        if(b<m && one[a][b+1] == 0){
            one[a][b+1] = tmp+1;
            q.push({a,b+1});
        }
    }

    cin >> x >> y;
    two[x][y] = 2;
    q.push({x,y});
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        int tmp = two[a][b];
        q.pop();
        if(a>1 && two[a-1][b] == 0){
            two[a-1][b] = tmp+1;
            q.push({a-1,b});
        }
        if(a<n && two[a+1][b] == 0){
            two[a+1][b] = tmp+1;
            q.push({a+1,b});
        }
        if(b>1 && two[a][b-1] == 0){
            two[a][b-1] = tmp+1;
            q.push({a,b-1});
        }
        if(b<m && two[a][b+1] == 0){
            two[a][b+1] = tmp+1;
            q.push({a,b+1});
        }
    }

    cin >> x >> y;
    thr[x][y] = 2;
    q.push({x,y});
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        int tmp = thr[a][b];
        q.pop();
        if(a>1 && thr[a-1][b] == 0){
            thr[a-1][b] = tmp+1;
            q.push({a-1,b});
        }
        if(a<n && thr[a+1][b] == 0){
            thr[a+1][b] = tmp+1;
            q.push({a+1,b});
        }
        if(b>1 && thr[a][b-1] == 0){
            thr[a][b-1] = tmp+1;
            q.push({a,b-1});
        }
        if(b<m && thr[a][b+1] == 0){
            thr[a][b+1] = tmp+1;
            q.push({a,b+1});
        }
    }

    int cnt = 0;
    int time = 987654321;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(one[i][j] == 1) continue;
            if(one[i][j] == 0 || two[i][j] == 0 || thr[i][j] == 0) continue;
            int tmp = max(one[i][j],two[i][j]);
            tmp = max(tmp,thr[i][j]);
            tmp -= 2;
            if(time > tmp){
                time = tmp;
                cnt = 1;
            }
            else if(time == tmp) cnt++;
        }
    }

    if(time == 987654321) cout << "-1";
    else{
        cout << time << "\n" << cnt;
    }
}
