#include <iostream>

using namespace std;

int w[31];
int check[15001] = {0}; //무게 있는지 체크
int check_[31][15001] = {0}; //특정 추 가 포함된 무게가 있는지 체크
int n;

int abs(int a){
    if(a > 0) return a;
    return -a;
}

//x는 추 번호, W는 현재 무게;
void dp(int x,int W){
    if(x > n+1) return;
    if(check_[x][W] == 1) return;
    check_[x][W] = 1;
    check[W] = 1;
    dp(x+1,W);
    dp(x+1,W+w[x]);
    dp(x+1,abs(W - w[x]));
}


int main()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }
    dp(1,0);
    int m;
    cin >> m;
    for(int i=1; i<=m; i++){
        int x;
        cin >> x;
        if(x <= 15000 && check[x] == 1) cout << "Y ";
        else cout << "N ";
    }
}
