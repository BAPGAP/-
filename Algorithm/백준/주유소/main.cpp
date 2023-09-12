#include <iostream>

using namespace std;

int len[100001];
int prz[100001];
long long sum = 0;
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> len[i];
    }
    cin >> prz[1];
    int tmp = prz[1];

    for(int i=2; i<=n; i++){
        cin >> prz[i];
        if(tmp < prz[i]){
            prz[i] = tmp;
        }
        else tmp = prz[i];
    }

    for(int i=1; i<n; i++){
        sum += len[i] * prz[i];
    }
    cout << sum << endl;
}
