#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp{
    bool operator()(vector<int> x,vector<int> y){
        if(x[0] == y[0]) return x[1] > y[1];
        return x[0] > y[0];
    }
};

priority_queue<vector<int>,vector<vector<int>>,cmp> pq; //贸府吝牢 老, index, 老贸府

int solution(int n, vector<int> cores) {
    for(int i=1; i<=cores.size(); i++){
        pq.push(vector<int>{0,i,cores[i-1]});
    }
    while(n--){
        int w = pq.top()[0];
        int index = pq.top()[1];
        int wp = pq.top()[2];
        cout << index << "\n";
        pq.pop();
        w += wp;
        pq.push(vector<int>{w,index,wp});
        if(n == 0) return index;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<3; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solution(n,v);
}
