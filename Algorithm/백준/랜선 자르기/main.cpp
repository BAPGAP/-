#include <iostream>

using namespace std;

long long l[10010];
long long sum = 0;
long long avg;
long long N;

int check(long long ans,int k,int n){
    N = 0;
    for(int i=1; i<=k; i++){
        N += l[i]/ans;
    }
    if(n <= N) return 1;
    else if(n > N) return 0;
}

int main()
{
    int k,n;
    cin >> k >> n;

    for(int i=1; i<=k; i++){
        cin >> l[i];
        sum += l[i];
    }

    avg = sum / n;
    long long L = 1;
    long long R = avg;

    while(1){
        if(L == R){
            cout << L;
            break;
        }
        if(R - L == 1){
            if(check(R,k,n)){
                cout << R;
                break;
            }
            cout << L;
            break;
        }
        int tmp = check((L+R)/2,k,n);
        if(tmp){
            L = (L+R)/2;
        }
        else R = (L+R)/2-1;
    }

}
