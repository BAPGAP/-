#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    cin >> a;
    for(int i=0; i<26; i++){
        char c = i + 97;
        if(a.find(c) == string::npos){
            cout << "-1 ";
        }
        else{
            cout << a.find(c) << " ";
        }
    }
    return 0;
}
