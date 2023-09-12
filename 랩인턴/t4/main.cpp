#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
vector<vector<int>> type_4;
int main()
{
    vector<int> tmp(4);
    tmp[0] = 0;
    for(int i=0; i<8; i++){
        tmp[1] = 0;
        tmp[2] = tmp[3] = i;
        type_4.push_back(tmp);
    }
    for(int i=1; i<8; i++){
        tmp[1] = i;
        for(int j=0; j<8; j++){
            tmp[2] = (tmp[0] + j)%8;
            tmp[3] = (tmp[1] + j)%8;
            type_4.push_back(tmp);
        }
    }
    ofstream out("type4.txt");
    if(out.is_open()){
        for(int i=0; i<type_4.size(); i++){
            for(int j=0; j<4; j++){
                out << type_4[i][j];
            }
            out << "\n";
        }
    }
}
