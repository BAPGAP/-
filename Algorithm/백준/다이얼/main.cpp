#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    int sum;
    int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0;
    cin >> a;
    for(int i=0; i<a.size()-1; i++){
        if(a[i] == 'c' && a[i+1] == '=') n1++;
        else if(a[i] == 'c' && a[i+1] == '-') n2++;
        else if(a[i] == 'd' && a[i+1] == '-') n3++;
        else if(a[i] == 'l' && a[i+1] == 'j') n4++;
        else if(a[i] == 'n' && a[i+1] == 'j') n5++;
        else if(a[i] == 's' && a[i+1] == '=') n6++;
        else if(a[i] == 'z' && a[i+1] == '=') n7++;
        else if(a[i] == 'd' && a[i+1] == 'z' && a[i+2] == '=' && i<a.size()-2) n8++;
    }
    sum = a.size() - (n1+n2+n3+n4+n5+n6+n7-n8) - (2 * n8);
    cout << sum << endl;
    return 0;
}
