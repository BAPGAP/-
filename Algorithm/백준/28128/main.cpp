#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int n,m;
string s[1002][1002];
vector<string> v;
map<string,int> msi;

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> s[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i<n-1 && s[i][j] == s[i+1][j]){
                if(msi.find(s[i][j]) == msi.end()){
                    msi[s[i][j]] = 1;
                    v.push_back(s[i][j]);
                }
            }
            else if(i<n-2 && s[i][j] == s[i+2][j]){
                if(msi.find(s[i][j]) == msi.end()){
                    msi[s[i][j]] = 1;
                    v.push_back(s[i][j]);
                }
            }
            else if(j<m-1 && s[i][j] == s[i][j+1]){
                if(msi.find(s[i][j]) == msi.end()){
                    msi[s[i][j]] = 1;
                    v.push_back(s[i][j]);
                }
            }
            else if(j<m-2 && s[i][j] == s[i][j+2]){
                if(msi.find(s[i][j]) == msi.end()){
                    msi[s[i][j]] = 1;
                    v.push_back(s[i][j]);
                }
            }
        }
    }
    if(v.size() == 0){
        cout << "MANIPULATED\n";
        return 0;
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }

}
