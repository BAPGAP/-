#include <iostream>

using namespace std;

int in(int x,int y,int r, int a,int b){
    if((a-x)*(a-x) + (b-y)*(b-y) - r*r < 0) return 1;
    else return 0;
}


int main()
{
    int n;
    cin >> n;
    int s1, s2, e1, e2;
    int m;
    int x,y,r;
    int sum;

    for(int i=0; i < n; i++){
        sum = 0;
        cin >> s1 >> s2 >> e1 >> e2;
        cin >> m;
        for(int j=0; j < m; j++){
            cin >> x >> y >> r;
            if(in(x,y,r,s1,s2) != in(x,y,r,e1,e2)) sum++;
        }
        cout << sum << "\n";
    }
}
