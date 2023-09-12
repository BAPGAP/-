#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

vector<vector<pair<int,int>>> n2(400);
vector<vector<vector<int>>> n4(400);

void initial(){
    vector<pair<int,int>> tmp;
    tmp.push_back(make_pair(0,1));
    n2[2] = tmp;
    vector<pair<int,int>>().swap(tmp);
    tmp.push_back(make_pair(1,2));
    tmp.push_back(make_pair(0,2));
    tmp.push_back(make_pair(0,1));
    n2[3] = tmp;
    vector<pair<int,int>>().swap(tmp);
    tmp.push_back(make_pair(3,4));
    tmp.push_back(make_pair(1,2));
    tmp.push_back(make_pair(2,4));
    tmp.push_back(make_pair(0,3));
    tmp.push_back(make_pair(1,3));
    tmp.push_back(make_pair(0,4));
    tmp.push_back(make_pair(1,4));
    tmp.push_back(make_pair(0,2));
    tmp.push_back(make_pair(2,3));
    tmp.push_back(make_pair(0,1));
    n2[5] = tmp;
}

void dp(int n){
    if(n2[n].size() != 0) return;
    int m = n/2;
    if(n%2 == 0){
        vector<pair<int,int>> tmp;
        dp(m);
        if(n%4 == 0){
            for(int i=0; i<n2[m].size(); i++){
                tmp.push_back(make_pair(n2[m][i].first,n2[m][i].second));
                tmp.push_back(make_pair(n2[m][i].first + m,n2[m][i].second + m));
            }
            for(int i=0; i<m; i++){
                for(int j=0; j<m; j++){
                    //(0,i) start -> (0+j,i+j)
                    tmp.push_back(make_pair(j,m+(i+j)%m));
                }
            }
            n2[n] = tmp;
            return;
        }
        int d = m/2;
        for(int i=0; i<n2[m].size()/d; i++){
            for(int j=0; j<d; j++){
                tmp.push_back(make_pair(n2[m][i*d+j].first,n2[m][i*d+j].second));
                tmp.push_back(make_pair(n2[m][i*d+j].first + m,n2[m][i*d+j].second + m));
            }
            tmp.push_back(make_pair(i,i+m));
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<m; j++){
                //(0,i) start -> (0+j,i+j)
                tmp.push_back(make_pair(j,m+(i+j)%m));
            }
        }
        n2[n] = tmp;
        return;

    }
    else{
        dp(n+1); //need (n+1,2)
        vector<pair<int,int>> tmp(n*(n-1)/2);
        int d = (n+1)/2; //d = k+1, n = 2k+1
        for(int i=0; i<n; i++){
            int pos;
            for(int j=0; j<d; j++){
                int x = n2[n+1][i*d+j].first;
                int y = n2[n+1][i*d+j].second;
                if(y == n){
                    pos = x;
                    break;
                }
            }
            int cnt = 0;
            for(int j=0; j<d; j++){
                int x = n2[n+1][i*d+j].first;
                int y = n2[n+1][i*d+j].second;
                if(y == n) continue;
                tmp[pos*(d-1)+cnt].first = x;
                tmp[pos*(d-1)+cnt].second = y;
                cnt++;
            }
        }
        n2[n] = tmp;
    }
}
void dp4(int n){
    vector<vector<int>> tmp;
    int m = n/2;
    dp(m);
    for(int i=0; i<n2[m].size()/2; i++){
        int x1 = n2[m][2*i].first;
        int y1 = n2[m][2*i].second;
        int x2 = n2[m][2*i+1].first;
        int y2 = n2[m][2*i+1].second;
        tmp.push_back(vector<int>{2*x1,2*x1+1,2*y1,2*y1+1});
        tmp.push_back(vector<int>{2*x2,2*x2+1,2*y2,2*y2+1});
        tmp.push_back(vector<int>{2*x1,2*y1,2*x2+1,2*y2+1});
        tmp.push_back(vector<int>{2*x1+1,2*y1+1,2*x2,2*y2});
    }
    n4[n] = tmp;

    string zero = "";
    for(int i=0; i<n; i++){
        zero += "0";
    }

    for(int i=0; i<n4[n].size(); i++){
        string s = zero;
        for(int j=0; j<4; j++){
            s[n4[n][i][j]] = '1';
        }
        cout << s << "\n";
    }
    cout << n4[n].size() << "\n";
    return;
}

int main()
{
    int n;
    cin >> n; //(n,2) 구하고싶어
    initial();
    dp4(n);

    /*dp(n);

    for(int i=0; i<n2[n].size(); i++){
        string zero = "";
        for(int j=0; j<n; j++){
            zero += "0";
        }
        int x = n2[n][i].first;
        int y = n2[n][i].second;
        zero[x] = '1';
        zero[y] = '1';
        cout << zero << "\n";
    }
    for(int i=0; i<n2[n].size()/(n/2); i++){
        string zero = "";
        for(int j=0; j<n; j++){
            zero += "0";
        }
        for(int j=0; j<n/2; j++){
            int x = n2[n][i*(n/2)+j].first;
            int y = n2[n][i*(n/2)+j].second;
            zero[x] = '1';
            zero[y] = '1';
        }
        cout << zero << "\n";
    }*/
}
