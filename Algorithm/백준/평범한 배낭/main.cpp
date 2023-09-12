#include <iostream>

using namespace std;

int val[100001]={0};
int mx=0;

int main()
{
    int n,k,x,v;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> x >> v;
        for(int j=k-x; j>=0; j--){
            if(val[j] + v > val[j+x]) {
                val[j+x] = val[j] + v;
                if(val[j+x] > mx) mx = val[j+x];
            }
        }
    }
    cout << mx;
}
