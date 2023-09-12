#include <iostream>
#include <map>

using namespace std;

map<string, int> M;

int main()
{
    string tmp;
    long double cnt = 0;
    while(cin >> tmp){
        if(M.find(tmp) == M.end()) M[tmp] = 1;
        else M[tmp]++;
        cnt++;
    }
    map<string,int>::iterator iter;
    long double answer = 1;
    for(iter = M.begin(); iter != M.end(); iter++){
        long double tp = (long double)((*iter).second)/cnt;
        answer -= tp * tp;
    }
    cout << answer;
}
