#include <iostream>
#include <vector>

using namespace std;

long long a[100001];

int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        long long Answer = 0;
        for(int i=1; i<n; i++){
            long long tmp = a[i] * a[i-1];
            if(Answer < tmp) Answer = tmp;
        }
        cout << Answer << "\n";
    }
}
