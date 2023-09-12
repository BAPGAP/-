#include <iostream>

using namespace std;

int a[100001];
int cnt[1001];
int total;

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    total = n;
    int pos = 1;
    int Answer = 0;
    while(pos <= n){
        int mx;
        for(int i=1000; i>=1; i--){
            if(cnt[i] > 0){
                mx = i;
                break;
            }
        }
        int sum = 0;
        for(int i=pos; i<=n; i++){
            cnt[a[i]]--;
            if(a[i] == mx){
                Answer += (i-1-pos+1) * mx - sum;
                pos = i+1;
                sum = 0;
                break;
            }
            else{
                sum += a[i];
            }
        }
    }
    cout << Answer;
}
