#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> vp;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n,k;
        cin >> n >> k;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            vp.push_back({x,i});
        }
        sort(vp.begin(),vp.end());
        int cnt = 1;
        for(int i=1; i<vp.size(); i++){
            if(vp[i-1].second + 1 != vp[i].second) cnt++;
        }
        if(cnt <= k) cout << "Yes\n";
        else cout << "No\n";
        vector<pair<int,int>>().swap(vp);
    }
}
