#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long long>> v;

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n,M;
    cin >> n >> M;
    for(int i=0; i<n; i++){
        long long x,y;
        cin >> x >> y;
        if(x < y){}
        else v.push_back(vector<long long>{y,x}); // y <- x
    }
    sort(v.begin(),v.end());
    long long sum = 0;
    long long pos = 0;
    long long L,R;
    L = 0;
    R = 0;
    for(int i=0; i<v.size(); i++){
        if(R < v[i][0]){
            sum += R - pos + R - L;
            pos = L;
            L = v[i][0];
            R = v[i][1];
        }
        else{
            R = max(R,v[i][1]);
        }
    }
    sum += R - pos + R - L + M - L;
    cout << sum;
}
