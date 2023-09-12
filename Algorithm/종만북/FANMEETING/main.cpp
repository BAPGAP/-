#include <iostream>
#include <string>
#include <vector>

using namespace std;

void add(vector<int>& x,const vector<int>& y,int k){
    if(x.size() < y.size() + k) x.resize(y.size() + k,0);

    for(int i=0; i < y.size(); i++){
        x[i+k] += y[i];
    }
}

void sub(vector<int>& x,const vector<int>& y){
    for(int i=0; i<y.size(); i++){
        x[i] -= y[i];
    }
}

vector<int> multiply(vector<int> x,vector<int> y){
    vector<int> z(x.size()+y.size()+1,0);
    for(int i=0; i<x.size(); i++){
        for(int j=0; j<y.size(); j++){
            z[i+j] += x[i] * y[j];
        }
    }
    return z;
}

vector<int> karatsuba(vector<int> a,vector<int> b){
    int an = a.size();
    int bn = b.size();
    if(an < bn) return karatsuba(b,a);
    if(an == 0 || bn == 0) return vector<int>();
    if(an <= 333) return multiply(a,b);
    int half = an/2;

    vector<int> a0(a.begin(),a.begin() + half);
    vector<int> a1(a.begin() + half,a.end());
    vector<int> b0(b.begin(),b.begin() + min<int>(b.size(),half));
    vector<int> b1(b.begin() + min<int>(b.size(),half), b.end());
    vector<int> z2 = karatsuba(a1,b1);
    vector<int> z0 = karatsuba(a0,b0);

    add(a0,a1,0);
    add(b0,b1,0);

    vector<int> z1 = karatsuba(a0,b0);

    sub(z1,z0);
    sub(z1,z2);

    vector<int> ret;

    add(ret,z0,0);
    add(ret,z1,half);
    add(ret,z2,half+half);

    return ret;
}

int hug(string member,string fan){
    int n = member.size();
    int m = fan.size();
    vector<int> A(n),B(m);
    for(int i=0; i<n; i++){
        A[i] = (member[i] == 'M');
    }
    for(int i=0; i<m; i++){
        B[m-i-1] = (fan[i] == 'M');
    }

    vector<int> C = karatsuba(A,B);
    int allhug = 0;
    for(int i=n-1; i<m; i++){
        if(C[i] == 0) allhug++;
    }
    return allhug;
}

int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        string s1,s2;
        cin >> s1 >> s2;
        cout << hug(s1,s2) << "\n";
    }
}
