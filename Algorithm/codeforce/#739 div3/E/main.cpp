#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void solve(string x){
    int cnt[26] = {0}; //a ~ z = 0 ~ 25
    bool visit[26] = {0};

    vector<char> Answer;

    for(int i=0; i<x.size(); i++){
        int tmp = x[i] - 'a';
        cnt[tmp]++;
        if(!visit[tmp]){
            visit[tmp] = true;
            Answer.push_back(x[i]);
        }
    }

    reverse(x.begin(),x.end());
    reverse(Answer.begin(),Answer.end());

    int pos = 0;

    for(int i=0; i<Answer.size(); i++){
        int tmp = Answer[i] - 'a';
        if(cnt[tmp] % (i+1)){
            cout << "-1\n";
            return;
        }
        pos += cnt[tmp]/(i+1);
    }

    string result = x.substr(0,pos); //예상 답안
    string A = result; //예상답안으로 만든 풀 답안

    for(int i=0; i<Answer.size(); i++){
        result.erase(remove(result.begin(),result.end(),Answer[i]),result.end());
        A += result;
    }

    if(A.size() != x.size()) cout << "-1\n";
    else{
        for(int i=0; i<A.size(); i++){
            if(A[i] != x[i]){
                cout << "-1\n";
                return;
            }
        }
        cout << x.substr(0,pos) << " ";
        for(auto c : Answer) cout << c;
        cout << "\n";
        return;
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        reverse(s.begin(),s.end());
        solve(s);
    }
}
