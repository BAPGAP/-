#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(string x,string y){
    if(x.size() == y.size()) return x < y;
    return x.size() < y.size();
}

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }

    return 0;
}
