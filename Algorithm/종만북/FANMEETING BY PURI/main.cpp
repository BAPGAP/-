#include <iostream>
#include <complex> //복소수를 저장하기 위함
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef complex<double> base;

double PI = 3.14159265358979;

void fft(vector<base> &a, bool inv) { //inv = true일때 역푸리에변환, false일때 푸리에변환
    int n = (int) a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
        double x = inv ? PI / i : -PI / i;
        base w = {cos(x), sin(x)};
        for (int j = 0; j < n; j += i << 1) {
            base th = {1, 0};
            for (int k = 0; k < i; k++) {
                base tmp = a[i + j + k] * th;
                a[i + j + k] = a[j + k] - tmp;
                a[j + k] += tmp;
                th *= w;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

int hug(const string& member,const string& fan){
    int N = member.size();
    int M = fan.size();
    int mx = max(N,M);
    int i = 0;
    while ((1 << i) < (mx << 1)) i++;
    mx = 1 << i;
    vector<base> A(mx,0),B(mx,0);
    for(int i=0; i<N; i++) A[i] = (member[i] == 'M');
    for(int i=0; i<M; i++) B[M-i-1] = (fan[i] == 'M');

    fft(A,false);
    fft(B,false);

    for(int i=0; i<mx; i++){
        A[i] *= B[i];
    }

    fft(A,true);

    int sum = 0;
    for(int i=N-1; i<M; i++){
        if((int)(A[i].real() + 0.5) == 0) sum++;
    }
    return sum;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        string s1,s2;
        cin >> s1 >> s2;
        cout << hug(s1,s2) << "\n";
    }
}
