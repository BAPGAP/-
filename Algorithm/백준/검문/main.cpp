#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a,int b){
    if(b < a) return gcd(b,a);

    if(a == 0) return b;

    if(b%a == 0) return a;

    return gcd(b%a,a);
}
int ab(int a,int b){
    if(a>b) return a-b;
    return b-a;
}


int a[100001];

int dir(int c){
    int cnt=0;
    for(int i=2; i<=sqrt(c); i++){
        if(i*i == c){
            a[cnt] = i;
            cnt++;
        }
        else if(c%i == 0){
            a[cnt] = i;
            cnt++;
            cout << i << " ";
        }
    }
    for(int i=cnt-1; i>=0; i--){
        cout << c/a[i] << " ";
    }
    cout << c;
    return 0;
}

int main()
{
    int n,tmp;
    int arr[101];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        if(i==2){
            tmp = ab(arr[i],arr[i-1]);
        }
        else if(i>2){
            tmp = gcd(tmp, ab(arr[i],arr[i-1]));
        }
    }
    dir(tmp);
    return 0;
}
