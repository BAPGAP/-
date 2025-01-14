#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        if(s == "push"){
            int x;
            cin >> x;
            q.push(x);
        }
        else if(s == "pop"){
            if(q.empty()) cout << "-1\n";
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(s == "size"){
            cout << q.size() << "\n";
        }
        else if(s == "empty"){
            if(q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if(s == "front"){
            if(q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        else if(s == "back"){
            if(q.empty()) cout << "-1\n";
            else cout << q.back() << "\n";
        }
    }
}
