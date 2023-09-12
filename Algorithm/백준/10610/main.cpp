#include <iostream>

using namespace std;

string s;

int cnt[10] = {0};

void print(){
    for(int i=9; i>=0; i--){
        for(int j=0; j<cnt[i]; j++){
            cout << i;
        }
    }
}

int main()
{
    cin >> s;
    int sum = 0;
    for(int i=0; i<s.size(); i++){
        int tmp = s[i] - '0';
        sum += tmp;
        cnt[tmp]++;
    }
    if(cnt[0] == 0) cout << "-1";
    else{
        int namujee = sum % 3;
        if(namujee == 0) print();
        else cout << "-1";
    }
}
