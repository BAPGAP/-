#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    char tmp[6];
    int icnt=0;
    int ccnt=0;
    int cnt=0;
    int a[51];
    char c[51];

    for(int i=0; i<s.size(); i++){
        if(s[i] == '+' || s[i] == '-'){
            c[ccnt] = s[i];
            ccnt++;
            a[cnt] = atoi(tmp);
            cnt++;
            icnt = 0;
            tmp[0] = '\n';
            tmp[1] = '\n';
            tmp[2] = '\n';
            tmp[3] = '\n';
            tmp[4] = '\n';
            tmp[5] = '\n';
        }
        else{
            tmp[icnt] = s[i];
            icnt++;
        }
        if(i==s.size()-1){
            a[cnt] = atoi(tmp);
            cnt++;
        }
    }
    int sum=a[0];
    int ismin = 0;
    for(int i=0; i<ccnt; i++){
        if(ismin == 1){
            sum -= a[i+1];
        }
        else if(c[i] == '+'){
            sum += a[i+1];
        }
        else if(c[i] == '-'){
            sum -= a[i+1];
            ismin = 1;
        }
    }
    cout << sum << endl;
}
