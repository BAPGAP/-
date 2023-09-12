#include <iostream>

using namespace std;

int mn=2147483647;
int n;
int a[21][21];
int ch[21] = {0};

void go(int x,int pos){

    if(x == (n/2)){
        int sum_1 = 0;
        int sum_2 = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i != j && ch[i] == 1 && ch[j] == 1){
                    sum_1 += a[i][j];
                }
                if(i != j && ch[i] == 0 && ch[j] == 0){
                    sum_2 += a[i][j];
                }
            }
        } // 능력치 계산

        if(sum_1 > sum_2){
            if(mn > sum_1 - sum_2) mn = sum_1 - sum_2;
        }
        else{
            if(mn > sum_2 - sum_1) mn = sum_2 - sum_1;
        }
        // 이전 값들과 비교한뒤 종료
        return;
    }

    for(int i=pos; i<=n; i++){
        if(ch[i] == 0){
            ch[i] = 1;
            if(ch[1] == 0) return; //절반의 경우 만 탐색(중복 경우 제외)
            go(x+1,i+1);
            ch[i] = 0;
        }
    }
}

int main()
{
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }

    go(0,1);

    cout << mn << endl;
    return 0;
}
