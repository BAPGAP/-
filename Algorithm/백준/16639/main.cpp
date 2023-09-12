#include <iostream>
#include <algorithm>
#include <string>
#define INF 2147483647

using namespace std;

int mn[20][20];
int mx[20][20];

string sick;
int n;
int dpmin(int,int);
int dpmax(int,int);

int main()
{
    cin >> n >> sick;
    fill(mn[0],mn[20],INF);
    fill(mx[0],mx[20],-INF);
    for(int i=0; i<n; i+=2){
        mn[i][i] = sick[i] - '0';
        mx[i][i] = sick[i] - '0';
    }
    cout << dpmax(0,n-1);
    return 0;

}

int dpmax(int x, int y){
    if(mx[x][y] != -INF) return mx[x][y];
    int mxm = -INF;
    for(int i=x+1; i<y; i+=2){
        if(sick[i] == '-'){
            mxm = max(mxm, dpmax(x,i-1) - dpmin(i+1,y));
        }
        else if(sick[i] == '+'){
            mxm = max(mxm, dpmax(x,i-1) + dpmax(i+1,y));
        }
        else if(sick[i] == '*'){
            mxm = max(mxm, dpmax(x,i-1) * dpmax(i+1,y));
            mxm = max(mxm, dpmax(x,i-1) * dpmin(i+1,y));
            mxm = max(mxm, dpmin(x,i-1) * dpmax(i+1,y));
            mxm = max(mxm, dpmin(x,i-1) * dpmin(i+1,y));
        }
    }
    return mx[x][y] = mxm;
}

int dpmin(int x, int y){
    if(mn[x][y] != INF) return mn[x][y];
    int mnm = INF;
    for(int i=x+1; i<y; i+=2){
        if(sick[i] == '-'){
            mnm = min(mnm, dpmin(x,i-1) - dpmax(i+1,y));
        }
        else if(sick[i] == '+'){
            mnm = min(mnm, dpmin(x,i-1) + dpmin(i+1,y));
        }
        else if(sick[i] == '*'){
            mnm = min(mnm, dpmax(x,i-1) * dpmax(i+1,y));
            mnm = min(mnm, dpmax(x,i-1) * dpmin(i+1,y));
            mnm = min(mnm, dpmin(x,i-1) * dpmax(i+1,y));
            mnm = min(mnm, dpmin(x,i-1) * dpmin(i+1,y));
        }
    }
    return mn[x][y] = mnm;
}
