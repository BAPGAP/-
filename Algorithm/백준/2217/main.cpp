#include <iostream>
#include <algorithm>

using namespace std;

long long L[100001];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> L[i];
    }
    sort(L+1,L+n+1);
    long long Answer = 0;
    for(int i=1; i<=n; i++){
        int tmp = L[i] * (n - i + 1);
        if(Answer < tmp) Answer = tmp;
    }
    cout << Answer;
}
