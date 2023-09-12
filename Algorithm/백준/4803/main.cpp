#include <iostream>

using namespace std;

int node[10001];

void postorder(int x,int y){
    if(x > y) return;
    else if(x == y) cout << node[x] << "\n";
    else{
        int parent = node[x];
        int pos;
        for(int i=x; i<=y; i++){
            if(parent < node[i]){
                pos = i;
                break;
            }
            if(i == y){
                pos = i+1;
            }
        }
        postorder(x+1,pos-1);
        postorder(pos,y);
        cout << parent << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int cnt = 0;
    while(1){
        cin >> node[cnt];
        cnt++;
        if(cin.eof()) break;
    }
    postorder(0,cnt-2);
}
