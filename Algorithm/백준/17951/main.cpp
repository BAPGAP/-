#include <iostream>
#include <cmath>

using namespace std;

int n,k;
int a[100001];

int main()
{
    cin >> n >> k;
    int x;
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int Answer;
    int L = 0;
    int R = sum;
    while(1){
        if(L + 1 == R){
            int tmp = 0;
            int cnt = 0;
            for(int i=0; i<n; i++){
                tmp = tmp + a[i];
                if(tmp >= R){
                    cnt++;
                    tmp = 0;
                }
            }
            if(cnt == k){
                Answer = R;
                break;
            }
            else{
                Answer = L;
                break;
            }
        }
        else if(L == R){
            Answer = R;
            break;
        }
        int M = (L+R)/2;
        int tmp = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            tmp = tmp + a[i];
            if(tmp >= M){
                cnt++;
                tmp = 0;
            }
        }


        if(cnt >= k){
            L = M;
        }
        else{
            R = M-1;
        }
    }
    cout << Answer;
}
