#include <iostream>

using namespace std;

int two[10] = {1,2,4,8,16,32,64,128,256,512};

int main()
{
    int n;
    cin >> n;
    int tmp = 0;
    while(tmp < 7){
        string s = "";
        for(int i=0; i<n; i++){
            if(i == n-1 && i%two[tmp+1] < two[tmp]) s += "B";
            else if(i%two[tmp+1] < two[tmp]) s += "A";
            else s += "B";
        }
        cout << s << "\n";
        tmp++;
    }
}
