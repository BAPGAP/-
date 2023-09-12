#include <iostream>

using namespace std;

typedef struct defqueue* Queue;

int a[101];

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
    Q -> Rear = (Q -> Rear + 1)%101;
    a[Q -> Rear] = x;
}

int pop(Queue Q){
    int tmp = a[Q -> Front];
    Q -> Front = (Q -> Front + 1)%101;
    Q -> Size -= 1;
    return tmp;
}

int printok(Queue Q){
    for(int i=1; i < Q -> Size; i++){
        if(a[Q -> Front] < a[(Q -> Front+i)%101]) return 0;
    }
    return 1;
}

void when(Queue Q, int c){
    if(Q -> Front == c){
        if(printok(Q)){
            return;
        }
        else{
            int tmp = pop(Q);
            push(tmp, Q);
            when(Q, Q -> Rear);
        }
    }
    else{
        if(printok(Q)){
            pop(Q);
            when(Q,c);
        }
        else{
            int tmp = pop(Q);
            push(tmp, Q);
            when(Q,c);
        }
    }
}

int main()
{
    Queue q;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int m,k;
        cin >> m >> k;
        for(int j=1; j<=m; j++){
            cin >> a[j];
        }
        q = ini(q,m);
        when(q,k+1);
        cout << m - (q -> Size) + 1 << "\n";
    }
}
