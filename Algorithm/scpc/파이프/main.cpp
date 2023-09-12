#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

int n;

mt19937_64 seed(428);
uniform_int_distribution<int> range(0, 1000);

int Answer;
struct Pipe
{
    long double x;
    long long r;
    int l;
};

Pipe P[101]; //x좌표, 반지름 , 처음 위치

bool compare(Pipe a,Pipe b)
{
    return a.r > b.r;
}

int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> P[i].r;
            P[i].l = i;
        }

        sort(P,P+n,compare);

        Pipe tmp[101];
        for(int i=0; 2*i<n; i++)
        {
            tmp[2*i] = P[i];
        }
        for(int i=0; 2*i+1 < n; i++)
        {
            tmp[2*i+1] = P[n-1-i];
        }
        for(int i=0; i<n; i++)
        {
            P[i] = tmp[i];
        }

        P[0].x = 0;
        P[1].x = 2 * sqrt(P[0].r * P[1].r);
        for(int i=2; i<n; i++)
        {
            if(sqrt(P[i-1].r * P[i-2].r) + sqrt(P[i].r * P[i-1].r) <= sqrt(P[i].r * P[i-2].r)) P[i].x = 2 * sqrt(P[i].r * P[i-2].r) + P[i-2].x;
            else P[i].x = P[i-1].x + 2 * sqrt(P[i].r * P[i-1].r);
        }

        //기본형

        for(int j=0; j<1000; j++){
            for(int i=0; i<n; i++){
                tmp[i] = P[i];
            }
            int pos1=0;
            int pos2=0;
            while(pos1 == pos2){
                pos1 = range(seed) % n;
                pos2 = range(seed) % n;
            }

            //pos1 <-> pos2

            Pipe tmp_p = tmp[pos1];
            tmp[pos1] = tmp[pos2];
            tmp[pos2] = tmp_p;

            tmp[0].x = 0;
            for(int i=1; i<n; i++){
                tmp[i].x = tmp[i-1].x + 2 * sqrt(tmp[i].r * tmp[i-1].r);
                for(int j=i-1; j>=0; j--){
                    if(tmp[i].x - tmp[j].x < 2 * sqrt(tmp[i].r * tmp[j].r)){
                        tmp[i].x = tmp[j].x + 2 * sqrt(tmp[i].r * tmp[j].r);
                    }
                }
            }

            if(tmp[n-1].x < P[n-1].x){
                for(int i=0; i<n; i++){
                    P[i] = tmp[i];
                }
            }
        }

        long double print[101];
        for(int i=0; i<n; i++)
        {
            print[P[i].l] = P[i].x;
        }

        cout.precision(20);
        cout << "Case #" << test_case+1 << endl;

        for(int i=0; i<n; i++)
        {
            cout << print[i] << endl;
        }
    }

    return 0;
}
