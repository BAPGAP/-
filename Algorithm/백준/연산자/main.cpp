#include <iostream>

using namespace std;

int n;
int a[12];
int giho[4];
int mx=-1000000000,mn=1000000000;
int sum[12];

void go(int z){

    if(z == n){
        if(sum[n-1] > mx) mx = sum[n-1];
        if(sum[n-1] < mn) mn = sum[n-1];
        return;
    }

    for(int i=0; i<4; i++){
        if(giho[i] != 0){
            giho[i]--;
            if(i==0) sum[z] = sum[z-1] + a[z];
            if(i==1) sum[z] = sum[z-1] - a[z];
            if(i==2) sum[z] = sum[z-1] * a[z];
            if(i==3) sum[z] = sum[z-1] / a[z];

            go(z+1);

            giho[i]++;

        }
    }

}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<4; i++){
        cin >> giho[i];
    }

    sum[0] = a[0];
    go(1);

    cout << mx << "\n" << mn << endl;

    return 0;
}
