#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int Answer = 0;
    stack<pair<int,int>> s;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 0 && !s.empty()){
            int cost = s.top().first;
            int minit = s.top().second;
            s.pop();
            if(minit == 1){
                Answer += cost;
            }
            else{
                minit -= 1;
                s.push(make_pair(cost,minit));
            }
        }
        else if(x == 1){
            int a,b;
            cin >> a >> b;
            if(b == 1){
                Answer += a;
            }
            else{
                s.push(make_pair(a,b-1));
            }
        }
    }
    cout << Answer;
}
