#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int Answer;
vector<pair<int,int>> v;
vector<int> s;

bool compare(pair<int,int> x,pair<int,int> y){
    if(x.first < y.first) return true;
    else if(x.first == y.first && x.second > y.second) return true;
    else return false;
}

void del_small(int x){
    int L = 0;
    int R = s.size() - 1;
    int M;
    while(L < R){
        M = (L + R)/2;
        if(x > s[M]){
            R = M;
        }
        else{
            L = M+1;
        }
    }
    s.erase(s.begin()+L,s.end());
}

void insert_it(int x){
    int L = 0;
    int R = s.size() - 1;
    int M;
    while(L < R){
        M = (L + R)/2;
        if(x >= s[M]){
            R = M;
        }
        else{
            L = M+1;
        }
    }
    s[L] = x;
}


int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n;
        cin >> n;
        int x,y;
        int mx=1;
        for(int i=0; i<n; i++){
            cin >> x >> y;
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(),v.end(),compare);

        s.push_back(v[0].first);

        for(int i=0; i<n; i++){
            if(v[i].first > s[s.size()-1]) del_small(v[i].first);

            if(v[i].second <= s[s.size()-1]){
                s.push_back(v[i].second);
                if(mx < s.size()) mx = s.size();
            }
            else{
                insert_it(v[i].second);
            }
        }

        v.clear();
        s.clear();

		cout << "Case #" << test_case+1 << endl;
		cout << mx << endl;
	}

	return 0;
}
