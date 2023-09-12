#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n;
    int pos=0;
    int L;
    cin >> n;
    for(int i=0; i<n; i++){
        string s1;
        cin >> s1;
        if(s1 == "char"){
            L = pos;
            pos += 2;

        }
        else if(s1 == "int"){
            L = pos;
            pos += 8;
        }
        else{
            L = pos;
            pos += 16;
        }
        long long sum = 0;
        long long sixteen = 1;
        for(int i=pos-1; i>=L; i--){
            if('0' <= s[i] && s[i] <= '9'){
                sum += sixteen * (long long)(s[i] - '0');
            }
            else sum += sixteen*((long long)(s[i] - 'a') + 10);
            sixteen *= 16;
        }
        cout << sum << " ";
    }
}
