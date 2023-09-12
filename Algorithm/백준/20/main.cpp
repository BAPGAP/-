#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;


vector<vector<double>> vvd;

int main()
{
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            double x = 2.0*i - 1.0;
            double y = 2.0*j - 1.0;
            double pp = 0.5 + sqrt(5.0)/2.0;
            double norm = sqrt(1.0 + pp*pp);

            cout << (pp*pp)/(pp*pp+1) << "\n";

            vvd.push_back(vector<double>{0.0,x*pp/norm,y/norm});
            vvd.push_back(vector<double>{x*pp/norm,y/norm,0.0});
            vvd.push_back(vector<double>{y/norm,0.0,x*pp/norm});
        }
    }


    int cnt = 0 ;
    double mx = -3000;
    for(int i=0; i<12; i++){
        for(int j=i+1; j<12; j++){
            double sum = 0;
            for(int k=0; k<3; k++){
                sum += vvd[i][k] * vvd[j][k];
            }
            cout << cnt << " " << sum << "\n";
            if(mx < sum) mx = sum;
            cnt++;
        }
    }
    cout << mx;
}
