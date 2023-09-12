#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int a[500001];

void in(int x){
    if(v.size() == 0){
        cout << "0 ";
        v.push_back(x);
    }
    else if(a[v[v.size()-1]] > a[x]){
        cout << v[v.size()-1] << " ";
        v.push_back(x);
    }
    else if(a[v[0]] < a[x]){
        cout << "0 ";
        vector<int>().swap(v);
        v.push_back(x);
    }
    else{
        int L = 0;
        int R = v.size() - 1;
        while(1){
            if(L == R){
                if(a[v[L]] == a[x]){
                    cout << v[L] << " ";
                    v.erase(v.begin() + L + 1,v.end());
                }
                else{
                    cout << v[L-1] << " ";
                    v.erase(v.begin() + L,v.end());
                    v.push_back(x);
                }
                break;
            }
            int M = (L+R)/2;
            if(a[v[M]] <= a[x]) R = M;
            else L = M+1;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        in(i);
    }
}
