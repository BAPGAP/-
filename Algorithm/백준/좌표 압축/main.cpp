#include <iostream>

using namespace std;

int a[1000001][2];
//a[x][0] = 처음 위치
//a[x][1] = 값
int b[1000001];
//b[x] = 답 저장
int s[1000001][2];


void hap(int q,int w,int e,int (*p)[2]){
    int l = q;
    int r = w+1;
    int cnt = 1;
    while(1){
        if(l>w || r>e) break;

        if(p[l][1] >= p[r][1]){
            s[cnt][1] = p[r][1];
            s[cnt][0] = p[r][0];
            r++;
            cnt++;
        }
        else{
            s[cnt][1] = p[l][1];
            s[cnt][0] = p[l][0];
            l++;
            cnt++;
        }
    }
    if(l>w){
        for(int i=r; i<=e; i++){
            s[cnt][1] = p[i][1];
            s[cnt][0] = p[i][0];
            cnt++;
        }
    }
    else{
        for(int i=l; i<=w; i++){
            s[cnt][1] = p[i][1];
            s[cnt][0] = p[i][0];
            cnt++;
        }
    }

    for(int i=q; i<=e; i++){
        p[i][1] = s[i-q+1][1];
        p[i][0] = s[i-q+1][0];
    }
}

void merg(int x,int y,int (*z)[2]){
    if(x<y){
    int m = (x+y)/2;
    merg(x,m,z);
    merg(m+1,y,z);
    hap(x,m,y,z);
    }
}



int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i][1];
        a[i][0] = i;
    }
    merg(1,n,a);
    int cnt = 0;
    int pre = a[1][1];
    for(int i=1; i<=n; i++){
        if(pre == a[i][1]){
            pre = a[i][1];
            a[i][1] = cnt;
        }
        else{
            pre = a[i][1];
            a[i][1] = ++cnt;
        }
    }
    for(int i=1; i<=n; i++){
        b[a[i][0]] = a[i][1];
    }
    for(int i=1; i<=n; i++){
        cout << b[i] << " ";
    }
}
