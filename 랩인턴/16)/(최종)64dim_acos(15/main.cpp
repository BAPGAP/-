#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

vector<vector<int>> cn1;

vector<double> rdvector(512); //random vector

vector<double> my_codeword(512);
vector<pair<double,int>> use;

vector<double> iron_mask(512);
vector<pair<double,int>> iron_need(512);

double pi = 3.14159265358979;

typedef pair<double,int> pdi;

bool compare(pdi x, pdi y){
    if(abs(x.first) > abs(y.first)) return true;
    else return false;
}

void make_codeword(){
    for(int i=0; i<16; i++){
        for(int j=i+1; j<16; j++){
            vector<int> tmp(8);
            for(int k=0; k<4; k++){
                tmp[k] = 4*i+k;
                tmp[k+4] = 4*j+k;
            }

            vector<int> tmp1(8);
            for(int k=0; k<2; k++){
                tmp1[k] = (4*i+60+k)%64;
                tmp1[k+2] = 4*i+2+k;
                tmp1[k+4] = 4*j+k;
                tmp1[k+6] = (4*j+6+k)%64;
            }
            cn1.push_back(tmp);
            if(i==0 || (i == 1 && j == 15)) continue;
            cn1.push_back(tmp1);
        }
    }
}

void my_decode(int s,int f){
    if(s+63 == f){
        vector<pair<double,int>> vp;
        for(int i=0; i<64; i++){
            vp.push_back(make_pair(rdvector[s+i],i));
        }
        sort(vp.begin(),vp.end(),compare);

        double mx = -987654321;
        vector<int> mx_idx;

        for(int i=0; i<cn1.size(); i++){
            vector<pdi> eight;
            for(int j=0; j<8; j++){
                int idx = cn1[i][j];
                eight.push_back(make_pair(rdvector[s+idx],idx));
            }
            sort(eight.begin(),eight.end());
            double sum_cn = 0;
            for(int j=0; j<4; j++){
                int idx = eight[j].second;
                sum_cn -= rdvector[s+idx];
            }
            for(int j=5; j<8; j++){
                int idx = eight[j].second;
                sum_cn += rdvector[s+idx];
            }
            vector<int> tmp(8);
            for(int j=0; j<8; j++){
                int idx = eight[j].second;
                tmp[j] = idx;
            }
            if(mx < sum_cn){
                mx = sum_cn;
                mx_idx.swap(tmp);
            }
        }
        //mx_idx 가 가장가까움 -1 -1 -1 -1 1 1 1 1의 index저장되어있음

        double sum1 = abs(vp[0].first) + abs(vp[1].first);//<1,1,0,0,0,0...,0,0> 일때
        double sum2 = mx; //<1,1,1,1,1,1,1,0,0,0,0,0,0,0>일때
        sum1 /= sqrt(2.0);
        sum2 /= sqrt(8.0);

        if(sum1 > sum2){
            cout << "ok\n";
            double go = 0.25;
            my_codeword[vp[0].second+s] = vp[0].first > 0 ? go : -go;
            my_codeword[vp[1].second+s] = vp[1].first > 0 ? go : -go;
            use.push_back(make_pair(sum1,s/64));
        }
        else{
            double go = 0.125;
            for(int i=0; i<4; i++){
                int idx = mx_idx[i];
                my_codeword[s+idx] = -go;
            }
            for(int i=4; i<8; i++){
                int idx = mx_idx[i];
                my_codeword[s+idx] = go;
            }
            use.push_back(make_pair(sum2,s/64));
        }
        return;
    }
    int m = (s+f)/2;
    my_decode(s,m);
    my_decode(m+1,f);
}

void iron_mask_decode(){
    sort(iron_need.begin(),iron_need.end(),compare);
    double sixteen = 0.25;
    for(int i=0; i<16; i++){
        iron_mask[iron_need[i].second] = iron_need[i].first > 0 ? sixteen : -sixteen;
    }
}

int main()
{
    make_codeword();
    //서로 60도가 아닌 코드워드 검사
    for(int i=0; i<cn1.size(); i++){
        for(int j=i+1; j<cn1.size(); j++){
            int a1[64] = {0},a2[64] = {0};
            for(int k=0; k<8; k++){
                a1[cn1[i][k]] = 1;
                a2[cn1[j][k]] = 1;
            }
            int sum = 0;
            for(int k=0; k<64; k++){
                sum += a1[k] * a2[k];
            }
            if(sum > 4) cout << "oh my god!\n";
        }
    }

	cout << "64 dim codeword : "<< cn1.size() << "\n";
    int iter = 0;
	random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-1, 1);
	cout << "my_code  iron_mask\n";
	while(iter++ < 500){
        vector<pdi>().swap(use);
        double rdsum = 0;
        for (int i = 0; i < 512; i++)
        {
            double tmp = dis(gen);
            rdvector[i] = tmp;
            rdsum += tmp*tmp;
        }
        //정규화
        double norm = sqrt(rdsum);
        for (int i = 0; i < 512; i++)
        {
            my_codeword[i] = 0;
            rdvector[i] /= norm;

            iron_mask[i] = 0;
            iron_need[i] = pdi{rdvector[i],i};
        }
        my_decode(0,511);
        iron_mask_decode();

        double insum = 0;
        double insum_iron = 0;
        double sum = 0;
        for(int i=0; i<512; i++){
            //cout << rdvector[i] << " " << my_codeword[i] << "\n";
            insum += rdvector[i] * my_codeword[i];
            insum_iron += rdvector[i] * iron_mask[i];
            sum += my_codeword[i] * my_codeword[i];
        }
        //cout << sum << "\n";
        cout<<fixed;
        cout.precision(4);
        cout << acos(insum)*180.0/pi << "  " << acos(insum_iron)*180.0/pi << "\n";
	}
    return 0;
}
