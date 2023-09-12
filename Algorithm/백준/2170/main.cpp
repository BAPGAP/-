#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> vp;

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        vp.push_back({x,y});
    }
    sort(vp.begin(),vp.end());

    int sum = 0;
    int L = vp[0].first;
    int R = vp[0].second;
    for(int i=1; i<vp.size(); i++){
        if(R < vp[i].first){
            sum += R - L;
            L = vp[i].first;
            R = vp[i].second;
        }
        else{
            R = max(R,vp[i].second);
        }
    }
    sum += R - L;
    cout << sum;
}
