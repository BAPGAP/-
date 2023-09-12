#include <iostream>
#include <vector>

using namespace std;

vector<int> v[27];

void preorder(int x){
    cout << (char)(x + 'A');
    if(v[x][0] != 27) preorder(v[x][0]);
    if(v[x][1] != 27) preorder(v[x][1]);
}
void inorder(int x){
    if(v[x][0] != 27) inorder(v[x][0]);
    cout << (char)(x + 'A');
    if(v[x][1] != 27) inorder(v[x][1]);
}
void postorder(int x){
    if(v[x][0] != 27) postorder(v[x][0]);
    if(v[x][1] != 27) postorder(v[x][1]);
    cout << (char)(x + 'A');
}
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char x,y,z;
        cin >> x >> y >> z;
        if(y != '.') v[(x - 'A')].push_back(y - 'A');
        else v[(x - 'A')].push_back(27);

        if(z != '.') v[(x - 'A')].push_back(z - 'A');
        else v[(x - 'A')].push_back(27);
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
}
