#include <iostream>

using namespace std;

typedef struct defqueue* Queue;

int a[51];
int gsum = 0;
int sum;
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
    Q -> Rear = (Q -> Rear+1)%51;
    a[Q -> Rear] = x;
}

int pop(Queue Q){
    int tmp = a[Q -> Front];
    Q -> Front = (Q -> Front+1)%51;
    Q -> Size -= 1;
    return tmp;
}

void printok(Queue Q,int c){
    if(a[Q -> Front] == c){
        if(sum > (Q -> Size) - sum) gsum += (Q -> Size) - sum;
        else gsum += sum;
        pop(Q);
        return;
    }
    else{
        int tmp = pop(Q);
        push(tmp, Q);
        sum++;
        printok(Q,c);
    }
}

int main()
{


    int n,k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        a[i] = i;
    }
    Queue q = ini(q,n);
    for(int i=0; i<k; i++){
        int x;
        cin >> x;
        sum = 0;
        printok(q,x);
    }
    cout << gsum << endl;
}
