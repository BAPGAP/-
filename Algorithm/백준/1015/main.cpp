#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[51];
vector<pair<int,int>> vp;
vector<pair<int,int>> v;
int pos[51];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        v.push_back({a[i],i});
    }
    stable_sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        pos[v[i].second] = i;
    }
    for(int i=0; i<n; i++){
        vp.push_back({i,pos[i]});
    }
    sort(vp.begin(),vp.end());
    for(int i=0; i<vp.size(); i++){
        cout << vp[i].second << " ";
    }
}
