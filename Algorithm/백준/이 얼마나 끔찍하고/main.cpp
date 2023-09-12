#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

map<string,string> M;
map<string,string> MB;
vector<string> vs;
stack<string> S;

int main()
{
    M["ONE"] = "1";
M["TWO"] = "2";
M["THREE"] = "3";
M["FOUR"] = "4";
M["FIVE"] = "5";
M["SIX"] = "6";
M["SEVEN"] = "7";
M["EIGHT"] = "8";
M["NINE"] = "9";
M["ZERO"] = "0";
    MB["0"] = "ZERO";
    MB["1"] = "ONE";
    MB["2"] = "TWO";
    MB["3"] = "THREE";
    MB["4"] = "FOUR";
    MB["5"] = "FIVE";
    MB["6"] = "SIX";
    MB["7"] = "SEVEN";
    MB["8"] = "EIGHT";
    MB["9"] = "NINE";
    MB["-"] = "-";
    string s;
    cin >> s;
    string sick = "";
    int start = 0;
    while(start < s.size()){
        string tmp;
        tmp = s.substr(start,1);
        if(tmp == "+" || tmp == "-" || tmp == "x" || tmp == "/" || tmp == "="){
            sick += tmp;
            start++;
            continue;
        }
        tmp = s.substr(start,3);
        if(M.find(tmp) != M.end()){
            sick += M[tmp];
            start += 3;
            continue;
        }
        tmp = s.substr(start,4);
        if(M.find(tmp) != M.end()){
            sick += M[tmp];
            start += 4;
            continue;
        }
        tmp = s.substr(start,5);
        if(M.find(tmp) != M.end()){
            sick += M[tmp];
            start += 5;
            continue;
        }
        cout << "Madness!";
        return 0;
    }
    start = 0;
    for(int i=0; i<sick.size(); i++){
        string tmp = sick.substr(i,1);
        if(tmp == "+" || tmp == "-" || tmp == "x" || tmp == "/" || tmp == "="){
            if(i != start) vs.push_back(sick.substr(start,i-start));
            vs.push_back(tmp);
            start = i+1;
        }
    }
    if(start != sick.size()){
        cout << "Madness!";
        return 0;
    }
    reverse(vs.begin(),vs.end());

    for(int i=0; i<vs.size(); i++){
        S.push(vs[i]);
    }
    while(S.size() > 2){
        string s1,s2,s3;
        s1 = S.top();
        S.pop();
        s2 = S.top();
        S.pop();
        s3 = S.top();
        S.pop();

        string tmp = s1;
        if(tmp == "+" || tmp == "-" || tmp == "x" || tmp == "/" || tmp == "="){
            cout << "Madness!";
            return 0;
        }
        tmp = s3;
        if(tmp == "+" || tmp == "-" || tmp == "x" || tmp == "/" || tmp == "="){
            cout << "Madness!";
            return 0;
        }
        long long gap1 = stoll(s1);
        long long gap2 = stoll(s3);
        long long gap;
        if(s2 == "+"){
            gap = gap1 + gap2;
            S.push(to_string(gap));
        }
        else if(s2 == "-"){
            gap = gap1 - gap2;
            S.push(to_string(gap));
        }
        else if(s2 == "x"){
            gap = gap1 * gap2;
            S.push(to_string(gap));
        }
        else if(s2 == "/"){
            gap = gap1/gap2;
            S.push(to_string(gap));
        }
        else{
            cout << "Madness!";
            return 0;
        }
    }
    string answer = S.top();
    S.pop();
    if(S.empty() || S.top() != "="){
        cout << "Madness!";
        return 0;
    }
    string real = "";
    for(int i=0; i<answer.size(); i++){
        string tmp = answer.substr(i,1);
        real += MB[tmp];
    }
    cout << sick << "\n";
    cout << real;
}
