#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

mt19937_64 seed(1000);
uniform_real_distribution<double> rng(0,1);

int coin[33][33]; //뒷면 1, 앞면 0
int n;
double t = 1;        // 현재 온도
double d = 0.9999;   // 온도감율
double k = 10;       // 볼츠만 상수
int Answer = 2000;


int scoring(){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cnt += coin[i][j];
        }
    }
    return cnt;
}

void turn(int x,int y){
    if(y==0){
        for(int i=0;  i<n; i++){
            coin[x][i] = 1 - coin[x][i];
        }
    }
    else{
        for(int i=0; i<n; i++){
            coin[i][x] = 1 - coin[i][x];
        }
    }
}

void func(){
    for(int i=0; i<n; i++){
        int s = 0;
        for(int j=0; j<n; j++){
            s += coin[j][i];
        }
        if(s > (n/2)) turn(i,1);
    }
}

void go(){
    double e1,e2;
    int tmp[33][33];
    for(int i=0; i<373333; i++){
        e1 = scoring();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                tmp[i][j] = coin[i][j];
            }
        }

        int pos = rand() % n;
        turn(pos,0);
        func();

        e2 = scoring();

        double p = exp((e1 - e2) / (k * t));
        if(p < rng(seed)){
            for(int i = 0; i<n; i++){
                for(int j=0; j<n; j++){
                    tmp[i][j] = coin[i][j];
                }
            }
        }

        k *= d;

        Answer = min(Answer, scoring());
    }
}



int main()
{
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            if(s[j] == 'H') coin[i][j] = 0;
            else coin[i][j] = 1;
        }
    }

    go();
    cout << Answer;

    return 0;
}
