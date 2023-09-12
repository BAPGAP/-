#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dim_64;

int main()
{
    for(int i=0; i<16; i++){
        for(int j=i+1; j<16; j++){
            vector<int> tmp(64);
            fill(tmp.begin(),tmp.end(),0);

            tmp[4*i] = tmp[4*i+1] = tmp[4*i+2] = tmp[4*i+3] = 1;
            tmp[4*j] = tmp[4*j+1] = tmp[4*j+2] = tmp[4*j+3] = 1;

            vector<int> tmp1(64);
            fill(tmp1.begin(),tmp1.end(),0);
            tmp1[(4*i+60)%64] = tmp1[(4*i+61)%64] = 1;
            tmp1[4*i+2] = tmp1[4*i+3] = 1;
            tmp1[4*j] = tmp1[4*j+1] = 1;
            tmp1[(4*j+6)%64] = tmp1[(4*j+7)%64] = 1;

            dim_64.push_back(tmp);
            if(i==0 || (i == 1 && j == 15)) continue;
            dim_64.push_back(tmp1);

        }
    }
    cout << dim_64.size() << "\n";

    for(int i=0; i<dim_64.size(); i++){
        for(int j=i+1; j<dim_64.size(); j++){
            int sum = 0;
            for(int k=0; k<64; k++){
                sum += dim_64[i][k] * dim_64[j][k];
            }
            if(sum > 4){
                cout << i << " " << j << "\n";
            }
        }
    }
}
