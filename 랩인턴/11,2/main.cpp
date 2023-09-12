#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> set_two[40];

void make_3(){
    vector<int> tmp(2);
    tmp[0] = 1;
    tmp[1] = 2; //"011"
    set_two[3].push_back(tmp);
    tmp[0] = 0;
    tmp[1] = 2; //"101"
    set_two[3].push_back(tmp);
    tmp[0] = 0;
    tmp[1] = 1; // "110"
    set_two[3].push_back(tmp);
}
void make_5(){
    vector<int> tmp(2);
    tmp[0] = 3;
    tmp[1] = 4; //"00011"
    set_two[5].push_back(tmp);
    tmp[0] = 1;
    tmp[1] = 2; //"01100"
    set_two[5].push_back(tmp);
    tmp[0] = 2;
    tmp[1] = 4; //"00101"
    set_two[5].push_back(tmp);
    tmp[0] = 0;
    tmp[1] = 3; //"10010"
    set_two[5].push_back(tmp);
    tmp[0] = 1;
    tmp[1] = 3; //"01010"
    set_two[5].push_back(tmp);
    tmp[0] = 0;
    tmp[1] = 4; //"10001"
    set_two[5].push_back(tmp);
    tmp[0] = 1;
    tmp[1] = 4; //"01001"
    set_two[5].push_back(tmp);
    tmp[0] = 0;
    tmp[1] = 2; //"10100"
    set_two[5].push_back(tmp);
    tmp[0] = 2;
    tmp[1] = 3; //"00110"
    set_two[5].push_back(tmp);
    tmp[0] = 0;
    tmp[1] = 1; //"11000"
    set_two[5].push_back(tmp);
}
void make_n(int n){
    int m = n/2;
    vector<int> tmp(2);
    vector<vector<int>> need = set_two[m];

    int need_size = need.size();
    int dis = m/2;

    for(int i=0; i<need_size/dis; i++){
        for(int j=0; j<dis; j++){
            tmp[0] = need[dis*i + j][0] + m+1;
            tmp[1] = need[dis*i + j][1] + m+1;
            set_two[n].push_back(tmp);

            tmp[0] = need[dis*i + j][0];
            tmp[1] = need[dis*i + j][1];
            set_two[n].push_back(tmp);
        }
        tmp[0] = m;
        tmp[1] = m+1+i;
        set_two[n].push_back(tmp);
    }

    for(int i=0; i<m; i++){
        tmp[0] = i;
        tmp[1] = m+1+i;
        set_two[n].push_back(tmp);
    }

    for(int i=0; i<need_size/dis; i++){
        for(int j=0; j<dis; j++){
            tmp[0] = need[dis*i + j][0];
            tmp[1] = need[dis*i + j][1] + m+1;
            set_two[n].push_back(tmp);
            tmp[0] = need[dis*i + j][0] + m+1;
            tmp[1] = need[dis*i + j][1];
            set_two[n].push_back(tmp);
        }
        tmp[0] = i;
        tmp[1] = m;
        set_two[n].push_back(tmp);
    }
}

int main()
{
    make_3();
    make_5();
    make_n(11);
    make_n(23);
    string zero = "";
    for(int i=0; i<5; i++){
        zero += "0";
    }
    for(int i=0; i<set_two[5].size(); i++){
        string tmp = zero;
        for(int j=0; j<2; j++){
            int x = set_two[5][i][j];
            tmp[x] = '1';
        }
        cout << tmp << "\n";
    }
    cout << set_two[5].size();
}
