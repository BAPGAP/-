#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int P[1000001] = {0};
vector<int> p;
int lim = sqrt(1000000);
int Answer[1000000] = {0};

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=2; i<=1000000; i++){
        if(P[i] == 0){
            p.push_back(i);
            if(i > lim) continue;
            for(int j=i*i; j<=1000000; j+=i){
                P[j] = 1;
            }
        }
    }

    int x;
    while(1){
        cin >> x;
        if(x == 0) break;
        if(Answer[x] == 0){
            for(int i=1; i<p.size(); i++){
                if(P[x - p[i]] == 0){
                    Answer[x] = p[i];
                    break;
                }
            }
        }
        cout << x << " = " << Answer[x] << " + " << x - Answer[x] << "\n";
    }
}
