#include <iostream>
#include <cmath>


using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int root = sqrt(a*a - b);
    if(root == 0) cout << -a;
    else{
        int a_ = -a + root;
        int b_ = -a - root;
        cout << min(a_,b_) << " " << max(a_,b_);
    }
}
