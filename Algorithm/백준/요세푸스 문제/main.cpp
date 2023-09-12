#include <iostream>

using namespace std;

typedef struct defqueue* Queue;

int a[1001];

struct defqueue{
    int Front;
    int Rear;
    int Size;
};

Queue ini(Queue Q,int s){
    Q = new struct defqueue;
    Q -> Front = 1;
    Q -> Rear = s;
    Q -> Size = s;
    return Q;
}

void push(int x,Queue Q){
    Q -> Size += 1;
    Q -> Rear = (Q -> Rear + 1)%1001;
    a[Q -> Rear] = x;
}

int pop(Queue Q){
    int x = a[Q -> Front];
    Q -> Front = (Q -> Front + 1)%1001;
    Q -> Size -= 1;
    return x;
}

int ans[1001];

int main()
{
    Queue q;
    int n,k;
    cin >> n >> k;
    q = ini(q,n);
    for(int i=1; i<=n; i++){
        a[i] = i;
    }
    int x = 1,cnt = 1;
    while(1){
        if(q -> Size == 0) break;

        if(x%k == 0){
            ans[cnt] = pop(q);
            cnt++;
        }
        else{
            int tmp = pop(q);
            push(tmp, q);
        }
        x++;
    }
    cout << "<";
    for(int i=1; i<n; i++){
        cout << ans[i] << ", ";
    }
    cout << ans[n] << ">";
}
