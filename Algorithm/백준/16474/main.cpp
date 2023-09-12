#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[2001];

int a[2001];
int b[2001];

int l[2001];
int cnt = 0;

bool compare(int x,int y){
    return x > y;
}

void in(int x){
    if(l[cnt] < x){
        cnt++;
        l[cnt] = x;
        return;
    }
    int L = 1;
    int R = cnt;
    int M;
    while(L < R){
        M = (L+R)/2;
        if(l[M] < x){
            L = M+1;
        }
        else{
            R = M;
        }
    }
    M = (L+R)/2;
    l[M] = x;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        a[x] = i;
    }
    for(int i=1; i<=m; i++){
        int x;
        cin >> x;
        b[x] = i;
    }
    int k;
    cin >> k;
    for(int i=1; i<=k; i++){
        int x,y;
        cin >> x >> y;
        int A = a[x];
        int B = b[y];
        //f(B) = A
        v[B].push_back(A);
    }
    for(int i=1; i<=m; i++){
        sort(v[i].begin(),v[i].end(),compare);
    }

    l[0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=0; j<v[i].size(); j++){
            in(v[i][j]);
        }
    }
    cout << k - cnt;
}
