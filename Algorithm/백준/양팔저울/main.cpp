#include <iostream>

using namespace std;

int w[31];
int check[15001] = {0}; //���� �ִ��� üũ
int check_[31][15001] = {0}; //Ư�� �� �� ���Ե� ���԰� �ִ��� üũ
int n;

int abs(int a){
    if(a > 0) return a;
    return -a;
}

//x�� �� ��ȣ, W�� ���� ����;
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
