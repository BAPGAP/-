#include <iostream>

using namespace std;

int arr[9]={1,1,1,1,1,1,1,1,1};
int n,m;

void print(){
    int sum=0;
    for(int i=m-1; i>=1; i--){
       if(arr[i] <= arr[i-1]) sum++;
    }
    if(sum == m-1){
        for(int i=m-1; i>=0; i--){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    cin >> n >> m;
    int x = 0;
    while(1){
        print();
        for(int i=0; i<m; i++){
            if(i==0) arr[i]++;
            if(arr[m-1] > n) return 0;
            if(arr[i] > n){
                arr[i] -= n;
                arr[i+1]++;
            }
        }
    }
    return 0;
}

