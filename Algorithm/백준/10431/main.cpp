#include <iostream>
#include <algorithm>

using namespace std;

int a[22];

int cnt(){
    int sum = 0;
    for(int i=2; i<=20; i++){
        int idx = 0;
        for(int j=i-1; j>0; j--){
            if(a[j] < a[i]){
                idx = j;
                break;
            }
        }
        sort(a+1, a+i+1);
        sum += i-idx-1;
    }
    return sum;
}

int main()
{
    int T;
    cin >> T;
    for(int i=1; i<=T; i++){
        int n;
        cin >> n;
        for(int j=1; j<=20; j++){
            cin >> a[j];
        }
        cout << n << " " << cnt() << "\n";
    }
}
