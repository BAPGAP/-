#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <time.h>
#include <string>


using namespace std;

typedef pair<vector<double>,double> pvdd;
typedef vector<vector<int>> vvi;
typedef vector<double> vd;
typedef vector<int> vi;
typedef vector<pair<double,int>> vpdi;

vvi type_4, type_3,type_3_start;
vvi cw;
vd rdvector(64);

void init(){
    string line;
    ifstream file("type4.txt");
    if(file.is_open()){
        while(getline(file,line)){
            vi tmp(4);
            for(int i=0; i<4; i++){
                tmp[i] = line[i] - '0';
            }
            type_4.push_back(tmp);
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
            type_3.push_back(tmp);
        }
        file.close();
    }
    file.open("type3_start.txt");
    if(file.is_open()){
        while(getline(file,line)){
            vi tmp;
            for(int i=0; i<8; i++){
                if(line[i] == '1') tmp.push_back(8*i);
            }
            type_3_start.push_back(tmp);
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
                element[k] = rdv[8*k + (type_4[i][k] + j)%8];
                element[k+4] = rdv[32 + 8*k + (type_4[i][k] + j)%8];
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
        vpd[k].first = rdv[8*k + (type_4[max_i][k] + j_in)%8];
        vpd[k].second = k;
        vpd[k+4].first = rdv[32 + 8*k + (type_4[max_i][k] + j_out)%8];
        vpd[k+4].second = k;
    }
    sort(vpd.begin(),vpd.begin()+4);
    sort(vpd.begin()+4,vpd.end());

    for(int j=0; j< 4; j++){
        int k = vpd[j].second;
        zero[8*k + (type_4[max_i][k] + j_in)%8] = j < 4-max_j ? -1 : 1;
        k = vpd[j+4].second;
        zero[32 + 8*k + (type_4[max_i][k] + j_out)%8] = j < max_j ? -1 : 1;
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

    for(int x=0; x<14; x++){

        vd element(8);

        for(int i=0; i<28; i++){
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
                    element[k] = rdv[type_3_start[x][k/2] + type_3[4*i+j][k]];
                    element[k+4] = rdv[type_3_start[x][k/2+2] + type_3[4*i+j][k]];
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
        vpd[k].first = rdv[type_3_start[max_x][k/2] + type_3[4*max_i+j_in][k]];
        vpd[k].second = k;
        vpd[k+4].first = rdv[type_3_start[max_x][k/2+2] + type_3[4*max_i+j_out][k]];
        vpd[k+4].second = k;
    }
    sort(vpd.begin(),vpd.begin()+4);
    sort(vpd.begin()+4,vpd.end());
    int k;
    for(int j=0; j< 4; j++){
        k = vpd[j].second;
        zero[type_3_start[max_x][k/2] + type_3[4*max_i+j_in][k]] = j < 4-max_j ? -1 : 1;
        k = vpd[j+4].second;
        zero[type_3_start[max_x][k/2+2] + type_3[4*max_i+j_out][k]] = j < max_j ? -1 : 1;
    }
    return make_pair(zero,max_val);
}

pvdd decode_all(vd &rdv, int s, int e){

    vd answer;
    double max_val = -70;

    for(int i=s; i<e; i++){
        vpdi vpd(8);
        for(int j=0; j<8; j++){
            vpd[j].first = rdv[cw[i][j]];
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
                zero[cw[i][vpd[j].second]] = -1;
                zero[cw[i][vpd[j+4].second]] = 1;
            }
            answer = zero;
        }
    }
    return make_pair(answer,max_val);
}

vd decode(vd &rdv){
    pvdd t_4 = decode_type_4(rdv); //type 4
    pvdd t_3 = decode_type_3(rdv); //type 3
    pvdd t_2 = decode_all(rdv,0,792);
    if(t_4.second > t_3.second && t_4.second > t_2.second) {cout << "4\n"; return t_4.first;}
    else if(t_3.second > t_4.second && t_3.second > t_2.second) {cout << "3\n"; return t_3.first;}
    cout << "2\n";
    return t_2.first;
}

void test(){ //7064 ~ 11159 까지 정말 있는지 확인 -> 정말 있음
    vector<int> num;
    for(int i=0; i<type_4.size(); i++){
        for(int k=0; k<8; k++){
            for(int l=0; l<8; l++){
                bool what = false;
                for(int j=0; j<11160; j++){
                    bool ok = true;
                    for(int m=0; m<4; m++){
                        if(8*m + (type_4[i][m]+k)%8 != cw[j][m]){
                            ok = false;
                            break;
                        }
                        if(32 + 8*m + (type_4[i][m]+l)%8 != cw[j][m+4]){
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        num.push_back(j);
                        what = true;
                        break;
                    }
                }
                if(!what){
                    cout << i << " " << k << " " << l << "\n";
                    return;
                }
            }
        }
    }
    sort(num.begin(),num.end());
    for(int i=0; i<num.size(); i++){
        if(num[i] != i+7064) cout << "ojojo";
    }
}
void test2(){
    for(int i=0; i<14; i++){ // 14*28*16 = 6272
        for(int k=0; k<28; k++){
            for(int l=0; l<4; l++){
                for(int m=0; m<4; m++){
                    bool what = false;
                    for(int j=0; j<11160; j++){
                        bool ok = true;
                        for(int n=0; n<4; n++){
                            if(cw[j][n] != type_3_start[i][n/2] + type_3[4*k+l][n]){
                                ok = false;
                                break;
                            }
                            if(cw[j][n+4] = type_3_start[i][n/2+2] + type_3[4*k+m][n]){
                                ok = false;
                                break;
                            }
                        }
                        if(ok){
                            cout << j << "\n";
                            what = true;
                            break;
                        }
                    }
                    if(!what){
                        cout << i << " " << k << " " << l << " " << m << "\n";
                        return;
                    }
                }
            }
        }
    }
}

void test3(){
    for(int i=0; i<11160; i++){
        if(cw[i][0] != 0) continue;
        if(cw[i][1] != 1) continue;
        if(cw[i][1] != 16) continue;
        if(cw[i][1] != 17) continue;
        if(cw[i][1] != 32) continue;
        if(cw[i][1] != 33) continue;
        if(cw[i][1] != 48) continue;
        if(cw[i][1] != 49) continue;
        cout << i <<"\n";
        break;
    }

}
int main()
{
    clock_t st,ed;
    double result;
    string line;
	ifstream file("output.txt");
	if(file.is_open()){
		while(getline(file, line)) {
            vi tmp;
            for(int i=0; i<64; i++){
                if(line[i] == '1') tmp.push_back(i);
            }
            cw.push_back(tmp);
		}
		file.close();
	}
    int iter = 0;
	random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-1, 1);

    init();

    test3();


/*
	while(iter++ < 100){
        double rdsum = 0;
        for(int i=0; i<64; i++){
            double tmp = dis(gen);
            rdvector[i] = tmp;
            rdsum += tmp*tmp;
        }
        double norm = sqrt(rdsum);
        for(int i=0; i<64; i++){
            rdvector[i] /= norm;
        }
        st = clock();
        vector<double> dc = decode(rdvector);
        ed = clock();
        result = (double)(ed - st);
        cout << "my decode 수행시간 : " << result/CLOCKS_PER_SEC << "\n";
        double sum1 = 0,sum2 = 0;
        for(int i=0; i<64; i++){
            sum1 += dc[i] * rdvector[i];
        }
        st = clock();
        vector<double> dc2 = decode_all(rdvector,0,11160).first;
        ed = clock();
        result = (double)(ed - st);
        cout << "all 수행시간 : " << result/CLOCKS_PER_SEC << "\n";
        for(int i=0; i<64; i++){
            sum2 += dc2[i] * rdvector[i];
        }
        if(sum1 > sum2){
            cout << sum1 << " " << sum2;
            return 0;
        }
    }
    */
}
