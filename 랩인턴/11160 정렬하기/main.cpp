#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <time.h>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

typedef pair<vector<double>,double> pvdd;
typedef vector<vector<int>> vvi;
typedef vector<double> vd;
typedef vector<int> vi;
typedef vector<pair<double,int>> vpdi;

vvi type4, type3,type3_start, type2,type2_start,nodap, all;
vd rdvector(512);
vector<vd> myvector(8,vd(64));
vd answer(512);
vd dc;

bool compare(pair<double,int> x,pair<double,int> y){
    if(abs(x.first) > abs(y.first)) return true;
    else return false;
}

void init(){
    string line;
    ifstream file("type4.txt");
    if(file.is_open()){
        while(getline(file,line)){
            vi tmp(4);
            for(int i=0; i<4; i++){
                tmp[i] = line[i] - '0';
            }
            type4.push_back(tmp);
        }
        file.close();
    }
    file.open("type3.txt");
    if(file.is_open()){
        while(getline(file,line)){
            vi tmp(4);
            for(int i=0; i<4; i++){
                tmp[i] = line[i] - '0';
            }
            type3.push_back(tmp);
        }
        file.close();
    }
    file.open("type3_start.txt");
    if(file.is_open()){
        while(getline(file,line)){
            vi tmp;
            for(int i=0; i<4; i++){
                int node = line[i] - '0';
                tmp.push_back(8*node);
            }
            type3_start.push_back(tmp);
        }
        file.close();
    }
    file.open("type2.txt");
    if(file.is_open()){
        while(getline(file,line)){
            vi tmp(4);
            for(int i=0; i<4; i++){
                tmp[i] = line[i] - '0';
            }
            type2.push_back(tmp);
        }
        file.close();
    }
    file.open("type2_start.txt");
    if(file.is_open()){
        while(getline(file,line)){
            vi tmp;
            for(int i=0; i<2; i++){
                int node = line[i] - '0';
                tmp.push_back(8*node);
            }
            type2_start.push_back(tmp);
        }
        file.close();
    }
    file.open("nodap.txt");
    if(file.is_open()){
        while(getline(file,line)){
            vi tmp;
            for(int i=0; i<64; i++){
                if(line[i] == '1') tmp.push_back(i);
            }
            nodap.push_back(tmp);
        }
        file.close();
    }
    file.open("output.txt");
    if(file.is_open()){
        while(getline(file,line)){
            vi tmp;
            for(int i=0; i<64; i++){
                if(line[i] == '1') tmp.push_back(i);
            }
            all.push_back(tmp);
        }
        file.close();
    }
}

pvdd decode_type_4(vd &rdv){ //rdv = 64,8

    double max_val = -70;
    int max_i;
    int max_j;
    int j_in;
    int j_out;
    vd element(8);

    for(int i=0; i<64; i++){
        double inmax[5],outmax[5];
        int inmax_pos[5],outmax_pos[5];
        for(int j=0; j<5; j++){
            inmax[j] = -70;
            outmax[j] = -70;
        }
        for(int j=0; j<8; j++){
            double sum1 = 0, sum2 = 0;
            for(int k=0; k<4; k++){
                element[k] = rdv[8*k + (type4[i][k] + j)%8];
                element[k+4] = rdv[32 + 8*k + (type4[i][k] + j)%8];
                sum1 += element[k];
                sum2 += element[k+4];
            }

            sort(element.begin(),element.begin()+4);
            sort(element.begin()+4,element.end());

            if(sum1 > inmax[4]){ // + + + +
                inmax[4] = sum1;
                inmax_pos[4] = j;
            }
            if(sum2 > outmax[4]){
                outmax[4] = sum2;
                outmax_pos[4] = j;
            }
            for(int k=0; k<4; k++){
                sum1 -= 2*element[k];
                sum2 -= 2*element[k+4];
                if(sum1 > inmax[3-k]){
                    inmax[3-k] = sum1;
                    inmax_pos[3-k] = j;
                }
                if(sum2 > outmax[3-k]){
                    outmax[3-k] = sum2;
                    outmax_pos[3-k] = j;
                }
            }
        }
        for(int j = 0; j<5; j++){
            if(inmax[j] + outmax[4-j] > max_val){
                max_val = inmax[j] + outmax[4-j];
                max_j = j;
                max_i = i;
                j_in = inmax_pos[j];
                j_out = outmax_pos[4-j];
            }
        }
    }
    vd zero(64);
    vpdi vpd(8);

    for(int k=0; k<4; k++){
        vpd[k].first = rdv[8*k + (type4[max_i][k] + j_in)%8];
        vpd[k].second = k;
        vpd[k+4].first = rdv[32 + 8*k + (type4[max_i][k] + j_out)%8];
        vpd[k+4].second = k;
    }
    sort(vpd.begin(),vpd.begin()+4);
    sort(vpd.begin()+4,vpd.end());

    for(int j=0; j< 4; j++){
        int k = vpd[j].second;
        zero[8*k + (type4[max_i][k] + j_in)%8] = j < 4-max_j ? -1 : 1;
        k = vpd[j+4].second;
        zero[32 + 8*k + (type4[max_i][k] + j_out)%8] = j < max_j ? -1 : 1;
    }
    return make_pair(zero,max_val);
}

pvdd decode_type_3(vd &rdv){
    double max_val = -70;
    int max_x;
    int max_i;
    int max_j;
    int j_in;
    int j_out;
    for(int x=0; x<type3_start.size(); x++){

        vd element(8);

        for(int i=0; i<type3.size()/4; i++){
            // type[4*i] , type[4*i+1], type[4*i+2], type[4*i+3] is set
            double inmax[5],outmax[5];
            int inmax_pos[5],outmax_pos[5];
            for(int j=0; j<5; j++){
                inmax[j] = -70;
                outmax[j] = -70;
            }
            for(int j=0; j<4; j++){
                double sum1 = 0, sum2 = 0;
                for(int k=0; k<4; k++){
                    element[k] = rdv[type3_start[x][k/2] + type3[4*i+j][k]];
                    element[k+4] = rdv[type3_start[x][k/2+2] + type3[4*i+j][k]];
                    sum1 += element[k];
                    sum2 += element[k+4];
                }
                sort(element.begin(),element.begin()+4);
                sort(element.begin()+4,element.end());

                if(sum1 > inmax[4]){ // + + + +
                    inmax[4] = sum1;
                    inmax_pos[4] = j;
                }
                if(sum2 > outmax[4]){
                    outmax[4] = sum2;
                    outmax_pos[4] = j;
                }
                for(int k=0; k<4; k++){
                    sum1 -= 2*element[k];
                    sum2 -= 2*element[k+4];
                    if(sum1 > inmax[3-k]){
                        inmax[3-k] = sum1;
                        inmax_pos[3-k] = j;
                    }
                    if(sum2 > outmax[3-k]){
                        outmax[3-k] = sum2;
                        outmax_pos[3-k] = j;
                    }
                }
            }
            for(int j=0; j<5; j++){
                if(inmax[j] + outmax[4-j] > max_val){
                    max_val = inmax[j] + outmax[4-j];
                    max_j = j;
                    max_i = i;
                    max_x = x;
                    j_in = inmax_pos[j];
                    j_out = outmax_pos[4-j];
                }
            }
        }
    }
    vd zero(64);
    vpdi vpd(8);

    for(int k=0; k<4; k++){
        vpd[k].first = rdv[type3_start[max_x][k/2] + type3[4*max_i+j_in][k]];
        vpd[k].second = k;
        vpd[k+4].first = rdv[type3_start[max_x][k/2+2] + type3[4*max_i+j_out][k]];
        vpd[k+4].second = k;
    }
    sort(vpd.begin(),vpd.begin()+4);
    sort(vpd.begin()+4,vpd.end());
    int k;
    for(int j=0; j< 4; j++){
        k = vpd[j].second;
        zero[type3_start[max_x][k/2] + type3[4*max_i+j_in][k]] = j < 4-max_j ? -1 : 1;
        k = vpd[j+4].second;
        zero[type3_start[max_x][k/2+2] + type3[4*max_i+j_out][k]] = j < max_j ? -1 : 1;
    }
    return make_pair(zero,max_val);
}

pvdd decode_type_2(vd &rdv){
    double max_val = -70;
    int max_x;
    int max_i;
    int max_j;
    int j_in;
    int j_out;
    for(int x=0; x<type2_start.size(); x++){

        vd element(8);

        for(int i=0; i<type2.size()/2; i++){
            // type[2*i] , type[2*i+1] is set
            double inmax[5],outmax[5];
            int inmax_pos[5],outmax_pos[5];
            for(int j=0; j<5; j++){
                inmax[j] = -70;
                outmax[j] = -70;
            }
            for(int j=0; j<2; j++){
                double sum1 = 0, sum2 = 0;
                for(int k=0; k<4; k++){
                    element[k] = rdv[type2_start[x][0] + type2[2*i+j][k]];
                    element[k+4] = rdv[type2_start[x][1] + type2[2*i+j][k]];
                    sum1 += element[k];
                    sum2 += element[k+4];
                }
                sort(element.begin(),element.begin()+4);
                sort(element.begin()+4,element.end());

                if(sum1 > inmax[4]){ // + + + +
                    inmax[4] = sum1;
                    inmax_pos[4] = j;
                }
                if(sum2 > outmax[4]){
                    outmax[4] = sum2;
                    outmax_pos[4] = j;
                }
                for(int k=0; k<4; k++){
                    sum1 -= 2*element[k];
                    sum2 -= 2*element[k+4];
                    if(sum1 > inmax[3-k]){
                        inmax[3-k] = sum1;
                        inmax_pos[3-k] = j;
                    }
                    if(sum2 > outmax[3-k]){
                        outmax[3-k] = sum2;
                        outmax_pos[3-k] = j;
                    }
                }
            }
            for(int j=0; j<5; j++){
                if(inmax[j] + outmax[4-j] > max_val){
                    max_val = inmax[j] + outmax[4-j];
                    max_j = j;
                    max_i = i;
                    max_x = x;
                    j_in = inmax_pos[j];
                    j_out = outmax_pos[4-j];
                }
            }
        }
    }
    vd zero(64);
    vpdi vpd(8);

    for(int k=0; k<4; k++){
        vpd[k].first = rdv[type2_start[max_x][0] + type2[2*max_i+j_in][k]];
        vpd[k].second = k;
        vpd[k+4].first = rdv[type2_start[max_x][1] + type2[2*max_i+j_out][k]];
        vpd[k+4].second = k;
    }
    sort(vpd.begin(),vpd.begin()+4);
    sort(vpd.begin()+4,vpd.end());
    int k;
    for(int j=0; j< 4; j++){
        k = vpd[j].second;
        zero[type2_start[max_x][0] + type2[2*max_i+j_in][k]] = j < 4-max_j ? -1 : 1;
        k = vpd[j+4].second;
        zero[type2_start[max_x][1] + type2[2*max_i+j_out][k]] = j < max_j ? -1 : 1;
    }
    return make_pair(zero,max_val);
}

pvdd decode_naive(vd &rdv,vvi tar){

    vd answer;
    double max_val = -70;

    for(int i=0; i<tar.size(); i++){
        vpdi vpd(8);
        for(int j=0; j<8; j++){
            vpd[j].first = rdv[tar[i][j]];
            vpd[j].second = j;
        }
        sort(vpd.begin(),vpd.end());
        double sum = 0;
        for(int j=0; j<4; j++){
            sum += vpd[4+j].first;
            sum -= vpd[j].first;
        }
        if(sum > max_val){
            max_val = sum;
            vd zero(64);
            for(int j=0; j<4; j++){
                zero[tar[i][vpd[j].second]] = -1;
                zero[tar[i][vpd[j+4].second]] = 1;
            }
            answer = zero;
        }
    }
    return make_pair(answer,max_val);
}

vd decode(vd &rdv){
    pvdd t_4 = decode_type_4(rdv); //type 4
    pvdd t_3 = decode_type_3(rdv); //type 3
    pvdd t_2 = decode_type_2(rdv); //type 2
    pvdd t_1 = decode_naive(rdv,nodap); //type 3 + type 1
    if(t_4.second >= t_3.second && t_4.second >= t_2.second && t_4.second >= t_1.second) return t_4.first;
    else if(t_3.second >= t_4.second && t_3.second >= t_2.second && t_3.second >= t_1.second) return t_3.first;
    else if(t_2.second >= t_4.second && t_2.second >= t_3.second && t_2.second >= t_1.second) return t_2.first;
    else return t_1.first;
}

vd iron_mask(vd &rdv){
    vector<pair<double, int>> element;
    for(int i=0; i<rdv.size(); i++){
        element.push_back(make_pair(rdv[i],i));
    }
    sort(element.begin(),element.end(),compare);
    vector<double> zero(512);
    for(int i=0; i<16; i++){
        zero[element[i].second] = element[i].first > 0 ? 0.25 : -0.25;
    }
    return zero;
}

int main()
{
    system_clock::time_point st, ed;
    nanoseconds nano;
    int iter = 0;
	random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-1, 1);

    init();

	while(iter++ < 1000){
        double rdsum = 0;
        for(int i=0; i<512; i++){
            double tmp = dis(gen);
            rdvector[i] = tmp;
            rdsum += tmp*tmp;
        }
        double norm = sqrt(rdsum);

        for(int i=0; i<512; i++){
            rdvector[i] /= norm;
            myvector[i/64][i%64] = rdvector[i];
        }

        for(int i=0; i<8; i++){
            dc = decode(myvector[i]);
            for(int j=0; j<64; j++){
                answer[i*64+j] = dc[j]/8;
            }
        }

        double sum = 0;
        for(int i=0; i<512; i++){
            sum += answer[i] * rdvector[i];
        }
        cout << acos(sum)*180/3.14159265358979 << "\n";



        /*
        dc = iron_mask(rdvector);

        double sum = 0;
        for(int i=0; i<512; i++){
            sum += dc[i] * rdvector[i];
        }
        cout << acos(sum)*180/3.14159265358979 << "\n";
        */
    }
}
