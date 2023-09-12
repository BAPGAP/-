#include <iostream>

using namespace std;

int t[400000]={0};
int Size = 0;

int abs(int a){
    if(a < 0) return -a;
    return a;
}

void init(int x){
    Size++;
    t[Size] = x;
    int node = Size;
    while(1){
        if(node == 1) break;

        if(abs(t[node]) < abs(t[node/2])){
            int tmp = t[node];
            t[node] = t[node/2];
            t[node/2] = tmp;
            node = node/2;
        }
        else if(abs(t[node]) == abs(t[node/2]) && t[node] < t[node/2]){
            int tmp = t[node];
            t[node] = t[node/2];
            t[node/2] = tmp;
            node = node/2;
        }
        else break;
    }
}

void pop(){
    if(Size == 0){
        cout << "0\n";
    }
    else{
        cout << t[1] << "\n";
        t[1] = t[Size];
        t[Size] = 0;
        Size--;
        int node = 1;
        while(1){
            if(t[node*2] == 0 && t[node*2+1] == 0) break;

            else if(t[node*2+1] == 0){
                if(abs(t[node]) > abs(t[node*2])){
                    int tmp = t[node*2];
                    t[node*2] = t[node];
                    t[node] = tmp;
                }
                else if(abs(t[node]) == abs(t[node*2]) && t[node] > t[node*2]){
                    int tmp = t[node*2];
                    t[node*2] = t[node];
                    t[node] = tmp;
                }
                break;
            }
            else if(abs(t[node]) < abs(t[node*2]) && abs(t[node]) < abs(t[node*2+1])) break;
            else if(abs(t[node*2]) == abs(t[node*2+1])){
                if(t[node*2] < t[node*2+1]){
                    if(abs(t[node*2]) == abs(t[node]) && t[node*2] >= t[node]) break;
                    else{
                        int tmp = t[node*2];
                        t[node*2] = t[node];
                        t[node] = tmp;
                        node = node*2;
                    }
                }
                else{
                    if(abs(t[node*2+1]) == abs(t[node]) && t[node*2+1] >= t[node]) break;
                    else{
                        int tmp = t[node*2+1];
                        t[node*2+1] = t[node];
                        t[node] = tmp;
                        node = node*2+1;
                    }
                }
            }
            else if(abs(t[node*2]) < abs(t[node*2+1])){
                if(abs(t[node*2]) == abs(t[node]) && t[node*2] >= t[node]) break;
                else{
                    int tmp = t[node*2];
                    t[node*2] = t[node];
                    t[node] = tmp;
                    node = node*2;
                }
            }
            else{
                if(abs(t[node*2+1]) == abs(t[node]) && t[node*2+1] >= t[node]) break;
                else{
                    int tmp = t[node*2+1];
                    t[node*2+1] = t[node];
                    t[node] = tmp;
                    node = node*2+1;
                }
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x == 0){
            pop();
        }
        else{
            init(x);
        }
    }
}
