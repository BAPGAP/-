#include <iostream>

using namespace std;

int p1[8] = {500,300,200,50,30,10,0};
int p2[8] = {512,256,128,64,32,0};
int a1[8] = {0,1,3,6,10,15,21,100};
int a2[8] = {0,1,3,7,15,31,100};

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int u,v;
        cin >> u >> v;
        int sum = 0;
        if(u != 0){
            for(int j=0; j<7; j++){
                if(a1[j] < u && u <= a1[j+1]){
                    sum += p1[j];
                    break;
                }
            }
        }
        if(v != 0){
            for(int j=0; j<6; j++){
                if(a2[j] < v && v <= a2[j+1]){
                    sum += p2[j];
                    break;
                }
            }
        }
        cout << sum * 10000 << "\n";
    }
}
