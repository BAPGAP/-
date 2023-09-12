#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

vector<vector<int>> cn1; //코드넘버의 1위치를 저장
vector<vector<int>> cn2;
vector<double> rdvector(512); //random vector

vector<double> my_codeword(512);
vector<double> original(512);
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
    if(s+63 == f){
        double mx = -999;
        int pos;
        for(int i=0; i<11160; i++){
            vector<pdi> eight(8);
            for(int j=0; j<8; j++){
                eight[j].first = rdvector[s + cn1[i][j]];
                eight[j].second = j;//원래 위치
            }
            sort(eight.begin(),eight.end());

            double sum_cn = 0;

            for(int j=0; j<4; j++){
                sum_cn += eight[j+4].first;
                sum_cn -= eight[j].first;
            }

            if(mx < sum_cn){
                mx = sum_cn;
                pos = i;
            }
        }
        for(int i=s; i<f; i++){
            my_codeword[i] = 0;
        }
        vector<pdi> eight(8);
        for(int j=0; j<8; j++){
            eight[j].first = rdvector[s + cn1[pos][j]];
            eight[j].second = j;//원래 위치
        }
        sort(eight.begin(),eight.end());

        for(int j=0; j<4; j++){
            my_codeword[s + cn1[pos][eight[j].second]] = -1/sqrt(40);
            my_codeword[s + cn1[pos][eight[j+4].second]] = 1/sqrt(40);
        }
        return;
    }
    int m = (s+f)/2;
    my_decode(s,m);
    my_decode(m+1,f);
}

void my_decode_2(int s,int f){
    if(s+127 == f){
        double mx = -999;
        int pos;
        for(int i=0; i<188976; i++){
            vector<pdi> eight(8);
            for(int j=0; j<8; j++){
                eight[j].first = rdvector[s + cn2[i][j]];
                eight[j].second = j;//원래 위치
            }
            sort(eight.begin(),eight.end());

            double sum_cn = 0;

            for(int j=0; j<4; j++){
                sum_cn += eight[j+4].first;
                sum_cn -= eight[j].first;
            }

            if(mx < sum_cn){
                mx = sum_cn;
                pos = i;
            }
        }
        for(int i=s; i<f; i++){
            my_codeword[i] = 0;
        }
        vector<pdi> eight(8);
        for(int j=0; j<8; j++){
            eight[j].first = rdvector[s + cn2[pos][j]];
            eight[j].second = j;//원래 위치
        }
        sort(eight.begin(),eight.end());

        for(int j=0; j<4; j++){
            my_codeword[s + cn2[pos][eight[j].second]] = -1/sqrt(40);
            my_codeword[s + cn2[pos][eight[j+4].second]] = 1/sqrt(40);
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
	ifstream file("output.txt");
	if(file.is_open()){
		while(getline(file, line)) {
            vector<int> tmp;
            for(int i=0; i<64; i++){
                if(line[i] == '1') tmp.push_back(i);
            }
            cn1.push_back(tmp);
		}
		file.close();
	}
	file.open("1288.txt");
	if(file.is_open()){
		while(getline(file, line)) {
            vector<int> tmp;
            for(int i=0; i<128; i++){
                if(line[i] == '1') tmp.push_back(i);
            }
            cn2.push_back(tmp);
		}
		file.close();
	}
    int iter = 0;
	random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-1, 1);
	cout << "my_code  iron_mask\n";
	while(iter++ < 50){
        vector<pdi>().swap(use);
        double rdsum = 0;
        for(int i=0; i<512; i++){
            double tmp = dis(gen);
            rdvector[i] = tmp;
            rdsum += tmp*tmp;
        }
        double norm = sqrt(rdsum);
        for(int i=0; i<512; i++){
            rdvector[i] /= norm;
            my_codeword[i] = 0;
        }

        my_decode(0,127);
        my_decode_2(128,255);
        my_decode_2(256,383);
        my_decode_2(384,511);

        double insum = 0;
        //double insum_iron = 0;
        double sum = 0;
        for(int i=0; i<512; i++){
            insum += rdvector[i] * my_codeword[i];
            //insum_iron += rdvector[i] * iron_mask[i];
            sum += my_codeword[i] * my_codeword[i];
        }
        //cout << sum << "\n";
        cout<<fixed;
        cout.precision(4);
        cout << acos(insum)*180.0/pi << "\n";
	}
    return 0;
}

