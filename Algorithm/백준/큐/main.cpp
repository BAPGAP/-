#include <iostream>

using namespace std;

typedef struct defqueue* Queue;

int a[2000000];

struct defqueue{
    int Front;
    int Rear;
    int Size;
};

Queue ini(Queue Q){
    Q = new struct defqueue;
    Q -> Front = 1;
    Q -> Rear = 0;
    Q -> Size = 0;
    return Q;
}

void push(int x,Queue Q){
    Q -> Size += 1;
    Q -> Rear += 1;
    a[Q -> Rear] = x;
}

int isempty(Queue Q){
    if(Q -> Size == 0) return 1;
    else return 0;
}

void pop(Queue Q){
    if(isempty(Q)) cout << "-1" << "\n";
    else{
        cout << a[Q -> Front] << "\n";
        Q -> Front += 1;
        Q -> Size -= 1;
    }
}
void big(Queue Q){
    cout << Q -> Size << "\n";
}

void L(Queue Q){
    if(isempty(Q)) cout << "-1" << "\n";
    else{
        cout << a[Q -> Front] << "\n";
    }
}

void R(Queue Q){
    if(isempty(Q)) cout << "-1" << "\n";
    else{
        cout << a[Q -> Rear] << "\n";
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    Queue q;
    q = ini(q);
    int n;
    cin >> n;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s == "push"){
            int x;
            cin >> x;
            push(x,q);
        }
        else if(s == "pop") pop(q);
        else if(s == "size") big(q);
        else if(s == "empty"){
            if(isempty(q)) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if(s == "front") L(q);
        else if(s == "back") R(q);
    }
}
