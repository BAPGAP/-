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

    //값을 재배열해서 바텀업으로 한번에 푸리에 변환을 할수있게한다

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }

    for (int i = 2; i <= n; i <<= 1) { //현재 푸리에 변환을 진행중인 수열 길이
        double x = inv ? 2 * PI / i : - 2 * PI / i;
        base w = {cos(x), sin(x)};
        for (int j = 0; j < n; j += i) { //변환할 수열의 시작 인덱스
            base th = {1, 0};
            for (int k = 0; k < i/2; k++) { //변환후? 인덱스를 나타내기위한 k
                base tmp = a[j + k + i/2] * th; //tmp : odd수열 * E^n
                a[j + k + i/2] = a[j + k] - tmp; //A_n+N/2 = even - odd * E^n = even - tmp
                a[j + k] += tmp; //A_n = even + odd * E^n = even + tmp
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

string s1,s2;
vector<base> v1,v2;
int main()
{
    cin >> s1 >> s2;
    v1.resize(s1.size());
    for(int i=0; i<s1.size(); i++){
        v1[s1.size() -1 - i].real(s1[i] - '0');
    }
    v2.resize(s2.size());
    for(int i=0; i<s2.size(); i++){
        v2[s2.size() - 1 - i].real(s2[i] - '0');
    }

    int n = (int) max(v1.size(), v2.size());
    int i = 0;
    while ((1 << i) < (n << 1)) i++;
    n = 1 << i;

    v1.resize(n,0);
    v2.resize(n,0);

    fft(v1,false);
    fft(v2,false);


    for(int i=0; i<n; i++){
        v1[i] *= v2[i];
    }

    fft(v1,true);

    long long sum = 0;

    vector<int> answer;

    for(int i=0; i<v1.size(); i++){
        sum += (long long)(v1[i].real() + 0.1);
        answer.push_back(sum%10);
        sum /= 10;
    }
    int pos;
    for(int i=answer.size()-1; i>=0; i--){
        if(answer[i] != 0){
            pos = i;
            break;
        }
    }
    for(int i=pos; i>=0; i--){
        cout << answer[i];
    }
}
