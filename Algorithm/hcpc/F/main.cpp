#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long e[1001];
long long c[1001];
vector<pair<long long,long long>> vp;

long long mx(long long x,long long y){
    if(x > y) return x;
    else return y;
}

bool compare(pair<long long,long long> x,pair<long long,long long> y){
    if(x.first >= y.first && x.second <= y.second) return true;
    else if(x.first + y.first - x.second >= y.first + x.first - y.second)
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> e[i];
    }
    for(int i=0; i<n; i++){
        cin >> c[i];
    }
    for(int i=0; i<n; i++){
        vp.push_back({e[i],c[i]});
    }

    for(int i=0; i<n; i++){
        for(int j)
    }
}
