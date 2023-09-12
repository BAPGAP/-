#include <iostream>
#include <set>

using namespace std;

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        set<int> s;
        int a,b;
        cin >> a >> b;
        int m = (a+b)/2;
        if((a+b) % 2 == 0){
            if(a > b) swap(a,b);
            for(int i=0; i<=a; i++){
                //a°¡ i°³
                //(a,b) = (i,a-i) , (m-i,b-m+i)
                s.insert(a+m-2*i);
            }
            set<int>::iterator iter;
            cout << s.size() << "\n";
            for(iter = s.begin(); iter != s.end(); iter++){
                cout << *iter << " ";
            }
            cout << "\n";
        }
        else{
            if(a > b) swap(a,b);
            for(int i=a; i>=0; i--){
                s.insert(a+m-2*i);
                s.insert(a+m+1-2*i);
            }
            set<int>::iterator iter;
            cout << s.size() << "\n";
            for(iter = s.begin(); iter != s.end(); iter++){
                cout << *iter << " ";
            }
            cout << "\n";
        }
    }
}
