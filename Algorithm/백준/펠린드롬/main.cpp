#include <iostream>

using namespace std;

int a[2001];
int ans[2001][2001] ={0};

int check(int L,int R){
    if(ans[L][R] != 0) return ans[L][R];
    else if(R - L == 1 && a[L] != a[R]) return ans[L][R] = 2;
    else if(R - L == 1) return ans[L][R] = 1;
    else if(a[L] == a[R]) return ans[L][R] = check(L+1,R-1);
    else return ans[L][R] = 2;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        ans[i][i] = 1;
    }
    int m;
    int l,r;
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> l >> r;
        cout << 2 - check(l,r) << "\n";
    }
}
