#include <iostream>
#include <algorithm>

using namespace std;

int a[1000];
int b[1000];
int n;

void S(int x){
    if(x%2){
        for(int i=1; i<n; i+=2){
            if(a[i] > a[i+1]) swap(a[i],a[i+1]);
        }
    }
    else{
        for(int i=2; i<n; i+=2){
            if(a[i] > a[i+1]) swap(a[i],a[i+1]);
        }
    }
}

bool check(){
    for(int i=1; i<=n; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b+1,b+n+1);
        if(check()){
            cout << "0" << "\n";
            continue;
        }
        for(int j=1; ; j++){
            S(j);
            if(check()){
                cout << j << "\n";
                break;
            }
        }
    }
}
