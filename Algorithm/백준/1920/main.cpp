#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        int index = lower_bound(v.begin(),v.end(),x) - v.begin();
        if(v[index] == x) cout << "1\n";
        else cout << "0\n";
    }
}
