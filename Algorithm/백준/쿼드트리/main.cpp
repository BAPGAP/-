#include <iostream>

using namespace std;

int a[129][129];

void paper(int x1,int x2,int y1,int y2){
    int ok = 1;
    int tmp = a[x1][y1];
    for(int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            if(a[x1][y1] != a[i][j]) ok = 0;
        }
    }
    if(ok){
        if(a[x1][y1] == 1){
            cout << "1";
            return;
        }
        else{
            cout << "0";
            return;
        }
    }
    int len = (x2 - x1 + 1)/2;
    cout << "(";
    paper(x1,x1+len-1,y1,y1+len-1);
    paper(x1,x1+len-1,y1+len,y2);
    paper(x1+len,x2,y1,y1+len-1);
    paper(x1+len,x2,y1+len,y2);
    cout << ")";
}


int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            a[i][j+1] = s[j] - '0';
        }
    }
    paper(1,n,1,n);
}
