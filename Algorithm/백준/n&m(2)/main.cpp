#include <iostream>

using namespace std;

int arr[9]={0};
int cheak[9]={0};
int n,m;

void go(int x){
    if(x == m){
        int sum = 0;
        for(int i=0; i<m-1; i++){
            if(arr[i] < arr[i+1]) sum++;
        }
        if(sum == m-1){
            for(int i=0; i<m; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for(int i=1; i<=n; i++){
        if(cheak[i] == 0){
            cheak[i] = 1;
            arr[x] = i;
            go(x+1);
            cheak[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    go(0);
    return 0;
}
