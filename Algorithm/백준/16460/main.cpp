#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<string> v;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string m1,m2;
    int m3;
    cin >> m1 >> m2 >> m3;
    int n;
    int cnt = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        string y1,y2;
        int y3;
        cin >> y1 >> y2 >> y3;
        if(m3 >= y3){
            if(m2 == y2 || m2 == "MF" || m2 == "FM"){
                v.push_back(y1);
            }
        }
    }
    if(v.size() == 0) cout << "No one yet";
    else{
        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            cout << v[i] << "\n";
        }
    }
}
