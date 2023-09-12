#include <iostream>
#include <string>
using namespace std;

string Reverse(string::iterator& it){
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w'){
        return string(1,head);
    }
    string UL = Reverse(it);
    string UR = Reverse(it);
    string LL = Reverse(it);
    string LR = Reverse(it);

    return string("x") + LL + LR + UL + UR;
}

int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        string s;
        cin >> s;
        string::iterator iter = s.begin();
        s = Reverse(iter);
        cout << s << "\n";
    }


    return 0;
}
