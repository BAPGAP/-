#include <iostream>

using namespace std;

typedef struct defqueue* Queue;

int a[500001];

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
    Q -> Rear = (Q -> Rear + 1)%500001;
    a[Q -> Rear] = x;
}

int pop(Queue Q){
    int x = a[Q -> Front];
    Q -> Front = (Q -> Front + 1)%500001;
    Q -> Size -= 1;
    return x;
}

int main()
{
    Queue q;
    int n;
    cin >> n;
    q = ini(q,n);
    for(int i=1; i<=n; i++){
        a[i] = i;
    }
    int x=1;
    while(1){
        if(q -> Size == 1){
            cout << a[q -> Front] << "\n";
            break;
        }

        if(x%2 == 1){
            pop(q);
        }
        else{
            int tmp = pop(q);
            push(tmp,q);
        }
        x++;
    }
}
