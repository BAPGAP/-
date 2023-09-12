#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
using namespace std;

vector<double> rdvector(512); //random vector

vector<double> iron_mask(512);
vector<pair<double,int>> iron_need(512);
vector<pair<double,double>> cd_type(3);
vector<double> minsu(512);

double pi = 3.14159265358979;

typedef pair<double,int> pdi;

bool compare(pdi x, pdi y){
    if(abs(x.first) > abs(y.first)) return true;
    else return false;
}

void iron_mask_decode(){
    sort(iron_need.begin(),iron_need.end(),compare);
    double sixteen = 0.25;
    for(int i=0; i<16; i++){
        iron_mask[iron_need[i].second] = iron_need[i].first > 0 ? sixteen : -sixteen;
    }
}

pdi find_type(double x, double y){
    double sum1 = cd_type[0].first * x + cd_type[0].second * y;
    double sum2 = cd_type[1].first * x + cd_type[1].second * y;
    double sum3 = cd_type[2].first * x + cd_type[2].second * y;

    if(sum1 > sum2 && sum1 > sum3) return make_pair(sum1,0);
    if(sum2 > sum3) return make_pair(sum2,1);
    return make_pair(sum3,2);
}

void minsu_decode(int s,int e){
    if(s+63 == e){
        vector<pair<double,int>> tmp;
        vector<int> tmp_best;
        for(int i=0; i<32; i++){
            pdi best_choice;
            best_choice = find_type(rdvector[s+2*i],rdvector[s+2*i+1]);
            tmp_best.push_back(best_choice.second);
            tmp.push_back(make_pair(best_choice.first,i));
        }
        sort(tmp.begin(),tmp.end());
        for(int i=29; i<32; i++){
            int idx = tmp[i].second;
            int idx_type = tmp_best[idx];
            minsu[s+idx*2] = cd_type[idx_type].first/sqrt(8);
            minsu[s+idx*2+1] = cd_type[idx_type].second/sqrt(8);
        }
        return;
    }
    int m = (s+e)/2;
    minsu_decode(s,m);
    minsu_decode(m+1,e);
}

int main()
{
    int iter = 0;
	random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-1, 1);
	cout << "minsu    iron_mask\n";
	while(iter++ < 50){
        double rdsum = 0;
        for (int i = 0; i < 512; i++)
        {
            double tmp = dis(gen);
            rdvector[i] = tmp;
            rdsum += tmp*tmp;
        }
        //Á¤±ÔÈ­
        double norm = sqrt(rdsum);
        for (int i = 0; i < 512; i++)
        {
            rdvector[i] /= norm;
            minsu[i] = 0;
            iron_mask[i] = 0;
            iron_need[i] = pdi{rdvector[i],i};
        }
        //ÁÂÇ¥ type
        double x32 = sqrt(3)/2.0;
        cd_type[0] = pdi{0,1};
        cd_type[1] = pdi{-x32,-0.5};
        cd_type[2] = pdi{x32,-0.5};

        iron_mask_decode();
        minsu_decode(0,511);

        double insum = 0;
        double insum_iron = 0;
        double insum_minsu = 0;
        double sum = 0;
        for(int i=0; i<512; i++){
            insum_iron += rdvector[i] * iron_mask[i];
            insum_minsu += rdvector[i] * minsu[i];
            sum += minsu[i]*minsu[i];
        }
        cout<<fixed;
        cout.precision(4);
        cout << acos(insum_minsu)*180.0/pi << "  " << acos(insum_iron)*180.0/pi << "\n";
        cout << sum << "\n"; //1ÀÌ ¾Æ´Ô!
	}
}
