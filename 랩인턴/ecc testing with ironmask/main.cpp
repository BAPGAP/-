#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

vector<vector<int>> cn1; //�ڵ�ѹ��� 1��ġ�� ����
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

void my_decode(int s,int f){
    if(s+15 == f){
        vector<pair<double,int>> vp;
        for(int i=0; i<16; i++){
            vp.push_back(make_pair(rdvector[s+i],i));
        }
        sort(vp.begin(),vp.end(),compare);

        double mx = -999;
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
        //mx_idx �� ���尡��� -1 -1 -1 -1 1 1 1 1�� index����Ǿ�����

        double sum1 = abs(vp[0].first) + abs(vp[1].first);//<1,1,0,0,0,0...,0,0> �϶�
        double sum2 = mx; //<1,1,1,1,1,1,1,0,0,0,0,0,0,0>�϶�
        sum1 /= sqrt(2);
        sum2 /= sqrt(8);

        if(sum1 > sum2){
            //cout << "use\n";
            double go = 1.0/sqrt(18);
            my_codeword[vp[0].second+s] = vp[0].first > 0 ? go : -go;
            my_codeword[vp[1].second+s] = vp[1].first > 0 ? go : -go;
            use.push_back(make_pair(sum1,s/16));
        }
        else{
            double go = 1.0/sqrt(72);
            for(int i=0; i<4; i++){
                int idx = mx_idx[i];
                my_codeword[s+idx] = -go;
            }
            for(int i=4; i<8; i++){
                int idx = mx_idx[i];
                my_codeword[s+idx] = go;
            }
            use.push_back(make_pair(sum2,s/16));
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
    string line;
	ifstream file("test.txt");
	if(file.is_open()){
		while(getline(file, line)) {
            vector<int> tmp;
            for(int i=0; i<16; i++){
                if(line[i] == '1') tmp.push_back(i);
            }
            cn1.push_back(tmp);
		}
		file.close();
	}
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
        //����ȭ
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

        sort(use.begin(),use.end());

        for(int i=0; i<23; i++){
            for(int j=0; j<16; j++){
                int pos = use[i].second;
                my_codeword[pos*16+j] = 0;
            }
        }

        double insum = 0;
        double insum_iron = 0;
        double sum = 0;
        for(int i=0; i<512; i++){
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

