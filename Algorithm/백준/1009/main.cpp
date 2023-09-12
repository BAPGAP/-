#include <iostream>

using namespace std;

int pow(int x,int y){
    if(y == 0) return 1;
    else if(y == 1) return x;
    int tmp = (x * x) %10;
    if(y%2 == 1) return (x * pow(tmp,(y-1)/2))%10;
    else return pow(tmp,y/2);
}

int main()
{
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        int a,b;
        cin >> a >> b;
        int Answer = pow(a%10,b);
        if(Answer%10 == 0) cout << "10\n";
        else cout << Answer << "\n";
    }
}
