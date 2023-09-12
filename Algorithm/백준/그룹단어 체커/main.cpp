#include <iostream>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++){
            for(int k=j+1; k<s.size()-1; k++){
                if(s[j] != s[k] && s[j] == s[k+1]){
                    sum++;
                    j=s.size();
                    break;
                }
            }
        }
    }
    cout << n-sum << endl;
    return 0;
}
