#include <iostream>

using namespace std;

int book[101];

int main()
{
    int n,m,l;
    cin >> n >> m >> l;
    int sum = 0;
    for(int i=1; i<=n; i++){
        cin >> book[i];
        sum += book[i];
    }
    if(sum == m){
        cout << "0";
    }
    else if(sum > m || l > m){
        cout << "-1";
    }
    else if(sum < l){
        if(sum + l <= m) cout << "1";
        else cout << "-1";
    }
    else cout << "1";
}
