#include <iostream>

using namespace std;

int m1=0;
int z = 0;
int p1=0;

int a[2188][2188];

void paper(int x1,int x2,int y1, int y2){
    int tmp = a[x1][y1];
    int ok = 1;
    for(int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            if(tmp != a[i][j]) ok = 0;
        }
    }
    if(ok){
        if(tmp == -1){
            m1++;
            return;
        }
        else if(tmp == 0){
            z++;
            return;
        }
        else{
            p1++;
            return;
        }
    }
    int len = (x2 - x1 + 1)/3;
    paper(x1,x1+len-1,y1,y1+len-1);
    paper(x1+len,x1+2*len-1,y1,y1+len-1);
    paper(x1+2*len,x2,y1,y1+len-1);

    paper(x1,x1+len-1,y1+len,y1+2*len-1);
    paper(x1+len,x1+2*len-1,y1+len,y1+2*len-1);
    paper(x1+2*len,x2,y1+len,y1+2*len-1);

    paper(x1,x1+len-1,y1+2*len,y2);
    paper(x1+len,x1+2*len-1,y1+2*len,y2);
    paper(x1+2*len,x2,y1+2*len,y2);
}


int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    paper(1,n,1,n);
    cout << m1 << "\n" << z << "\n" << p1;
}
