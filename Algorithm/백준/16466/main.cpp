#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        if(v[i]-i != 1){
            cout << i+1;
            return 0;
        }
    }
    cout << n+1;
}
