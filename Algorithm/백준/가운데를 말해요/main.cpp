#include <iostream>

using namespace std;

int t_mx[500000]={0};
int t_mn[500000]={0};
int Size_mx = 0;
int Size_mn = 0;

void init_mx(int x){
    Size_mx++;
    t_mx[Size_mx] = x;
    int node = Size_mx;
    while(1){
        if(node == 1) break;

        if(t_mx[node] > t_mx[node/2]){
            int tmp = t_mx[node];
            t_mx[node] = t_mx[node/2];
            t_mx[node/2] = tmp;
            node = node/2;
        }
        else break;
    }
}

void pop_mx(){
    if(Size_mx == 0) return;
    t_mx[1] = t_mx[Size_mx];
    t_mx[Size_mx] = 0;
    Size_mx--;
    int node = 1;
    while(1){
        if(node*2 > Size_mx) break;
        else if(node*2 == Size_mx){
            if(t_mx[node*2] > t_mx[node]){
                int tmp = t_mx[node*2];
                t_mx[node*2] = t_mx[node];
                t_mx[node] = tmp;
                node = node*2;
            }
            break;
        }
        else if(t_mx[node] >= t_mx[node*2] && t_mx[node] >= t_mx[node*2+1]) break;
        else if(t_mx[node*2] > t_mx[node*2+1]){
            int tmp = t_mx[node*2];
            t_mx[node*2] = t_mx[node];
            t_mx[node] = tmp;
            node = node*2;
        }
        else{
            int tmp = t_mx[node*2+1];
            t_mx[node*2+1] = t_mx[node];
            t_mx[node] = tmp;
            node = node*2+1;
        }
    }
}


void init_mn(int x){
    Size_mn++;
    t_mn[Size_mn] = x;
    int node = Size_mn;
    while(1){
        if(node == 1) break;

        if(t_mn[node] < t_mn[node/2]){
            int tmp = t_mn[node];
            t_mn[node] = t_mn[node/2];
            t_mn[node/2] = tmp;
            node = node/2;
        }
        else break;
    }
}

void pop_mn(){
    if(Size_mn == 0) return;
    t_mn[1] = t_mn[Size_mn];
    t_mn[Size_mn] = 0;
    Size_mn--;
    int node = 1;
    while(1){
        if(node*2 > Size_mn) break;
        else if(node*2 == Size_mn){
            if(t_mn[node*2] < t_mn[node]){
                int tmp = t_mn[node*2];
                t_mn[node*2] = t_mn[node];
                t_mn[node] = tmp;
                node = node*2;
            }
            break;
        }
        else if(t_mn[node] <= t_mn[node*2] && t_mn[node] <= t_mn[node*2+1]) break;
        else if(t_mn[node*2] < t_mn[node*2+1]){
            int tmp = t_mn[node*2];
            t_mn[node*2] = t_mn[node];
            t_mn[node] = tmp;
            node = node*2;
        }
        else{
            int tmp = t_mn[node*2+1];
            t_mn[node*2+1] = t_mn[node];
            t_mn[node] = tmp;
            node = node*2+1;
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
        if(Size_mn == Size_mx){
            init_mx(x);
        }
        else init_mn(x);

        if(Size_mn != 0){
            if(t_mx[1] > t_mn[1]){
                int tmp = t_mx[1];
                int tmp_ = t_mn[1];
                pop_mn();
                pop_mx();
                init_mn(tmp);
                init_mx(tmp_);
            }
        }
        cout << t_mx[1] << "\n";
    }
}
