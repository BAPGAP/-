#include <iostream>

using namespace std;

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int q,m;
    cin >> q >>m;

    string s = "11";
    int node1 = 1;
    int node2 = 1;

    while(1){
        int next = (node1 + node2)%m;
        if(node2 == 1 && next == 1) break;
        s += to_string(next);
        node1 = node2;
        node2 = next;
    }

    // 0 ~ s.size()-2

    long long big = s.size()-1;

    while(q--){
        long long x;
        cin >> x;
        long long tmp = x%big;
        if(tmp == 0) cout << s[big-1] << "\n";
        else cout << s[tmp-1] << "\n";
    }
}
