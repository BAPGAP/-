#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> set4_2;
vector<string> set4;
vector<string> set9_2;
vector<string> rd;

string comp(string x,string y){
    string tmp = "";
    for(int i=0; i<x.size(); i++){
        tmp += (x[i] == y[i]) ? "1" : "0";
    }
    return tmp;
}

string str_merge(string x,string y){
    string tmp = "";
    for(int i=0; i<x.size(); i++){
        tmp += (x[i] == y[i]) ? "0" : "1";
    }
    return tmp;
}

int main()
{
    // ½ÇÁ¦·Î 9 C 2 = 36°³ / 4 = 9 ½Ö
    set4_2.push_back("1100");
    set4_2.push_back("0011");
    set4_2.push_back("0101");
    set4_2.push_back("1010");
    set4_2.push_back("0110");
    set4_2.push_back("1001");

    set4.push_back("1000");
    set4.push_back("0100");
    set4.push_back("0010");
    set4.push_back("0001");

    rd.push_back("0010");
    rd.push_back("0100");
    rd.push_back("0001");
    rd.push_back("1000");
    string zero = "0000";
    for(int i=0; i<4; i++){
        for(int j=i; j<4; j++){
            if(i==j && i>1) continue;
            string tmp1,tmp2,tmp3,tmp4;
            tmp1 = set4[i] + "0" + set4[j];
            if(i==j){
                tmp2 = set4[3-i] + "0" + set4[3-i];
            }
            else{
                tmp2 = set4[j] + "0" + set4[i];
            }
            if((i+j)%2==0){
                tmp3 = zero + "0" + comp(tmp1.substr(0,4),tmp2.substr(0,4));
                tmp4 = rd[(i+(j+1)/2)] + "1" + zero;
            }
            else{
                tmp3 = comp(tmp1.substr(0,4),tmp2.substr(0,4)) + "0" + zero;
                tmp4 = zero + "1" + rd[(i+j/2)];
            }
            set9_2.push_back(tmp1);
            set9_2.push_back(tmp2);
            set9_2.push_back(tmp3);
            set9_2.push_back(tmp4);
        }
    }
    set9_2.push_back("10100" + zero);
    set9_2.push_back("01010" + zero);
    set9_2.push_back(zero + "01100");
    set9_2.push_back(zero + "00011");
    for(int i=0; i<set9_2.size(); i++){
        cout << set9_2[i] << "\n";
    }
    cout << set9_2.size() << "\n";
    zero = zero + zero + "0";
    for(int i=0; i<9; i++){
        string tmp = zero;
        for(int j=0; j<4; j++){
            tmp = str_merge(set9_2[i*4+j],tmp);
        }
        cout << tmp << "\n";
    }
}
