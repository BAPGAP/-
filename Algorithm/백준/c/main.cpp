#include <iostream>

using namespace std;

int a[5001];
int check[200001] = {0};

int main(){
    int sum = 0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(check[a[i] - a[j] + 100000] == 1){
                sum++;
                break;
            }
        }
        for(int j=0; j<=i; j++){
            check[a[i] + a[j] + 100000] = 1;
        }
    }
    cout << sum;

    return 0;
}
