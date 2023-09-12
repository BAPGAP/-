#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int card[400001] = {0};

bool compare(int a,int b){
    return a > b;
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int x,y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        card[x] = 1;
        card[y] = 1;
    }
    cin >> x >> y;
    card[x] = 1;
    card[y] = 1;
    int gizun = abs(x%k - y%k);
    vector<int> C;

    for(int i=1; i<=4*n; i++){
        if(card[i] == 0){
            C.push_back(i%k);
        }
    }
    sort(C.begin(),C.end(),compare);

    int sum = 0;
    int pos1,pos2 = 0;
    int len = C.size();
    for(int i=0; i<len; i++){
        pos1 = i;
        while(pos2 < len){
            if(C[pos1] - C[pos2] > gizun){
                sum++;
                pos2++;
                break;
            }
            pos2++;
        }

        if(pos2 == len) break;
    }
    if(sum >= m) sum = m-1;
    cout << sum;
}
