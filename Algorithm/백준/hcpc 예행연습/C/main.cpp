#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string name1[5001];
string name2[5001];
vector<int> adj1[5001];
vector<int> adj2[5001];

bool compare1(int x,int y){
    return name1[x] < name1[y];
}
bool compare2(int x,int y){
    return name2[x] < name2[y];
}

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        name1[i] = s;
    }
    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;
        adj1[x].push_back(y);
        adj1[y].push_back(x);
    }
    for(int i=0; i<n; i++){
        sort(adj1[i].begin(),adj1[i].end(),compare1);
    }

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        name2[i] = s;
    }
    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;
        adj2[x].push_back(y);
        adj2[y].push_back(x);
    }
    for(int i=0; i<n; i++){
        sort(adj2[i].begin(),adj2[i].end(),compare2);
    }
}
