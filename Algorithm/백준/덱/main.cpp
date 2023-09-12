#include <iostream>

using namespace std;

//덱 = Deque (Double Ended Queue) 양방향으로 넣고 빼기 가능

typedef struct typedeq* Deque;

int Size;

struct typedeq{
    int data;
    Deque L;
    Deque R;
};

Deque makeDeq(Deque Q){
    Q = new struct typedeq;
    Q -> L = Q;
    Q -> R = Q;
    Size = 0;
    return Q;
}

void push_L(int x, Deque Q){
    Deque A = new struct typedeq;
    A -> data = x;
    A -> L = Q -> L;
    A -> R = Q;
    (Q -> L) -> R = A;
    Q -> L = A;
    Size++;
}

void push_R(int x, Deque Q){
    Deque A = new struct typedeq;
    A -> data = x;
    A -> R = Q -> R;
    A -> L = Q;
    (Q -> R) -> L = A;
    Q -> R = A;
    Size++;
}

void pop_L(Deque Q){
    if(Size == 0) cout << "-1" << "\n";
    else{
        cout << (Q -> L) -> data << "\n";
        Deque tmp = Q -> L;
        ((Q -> L) -> L) -> R = Q;
        Q -> L = (Q -> L) -> L;
        delete tmp;
        Size--;
    }
}

void pop_R(Deque Q){
    if(Size == 0) cout << "-1" << "\n";
    else{
        cout << (Q -> R) -> data << "\n";
        Deque tmp = Q -> R;
        ((Q -> R) -> R) -> L = Q;
        Q -> R = (Q -> R) -> R;
        delete tmp;
        Size--;
    }
}

void print_L(Deque Q){
    if(Size == 0) cout << "-1" << "\n";
    else{
        cout << (Q -> L) -> data << "\n";
    }
}

void print_R(Deque Q){
    if(Size == 0) cout << "-1" << "\n";
    else{
        cout << (Q -> R) -> data << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    string s;
    Deque q = makeDeq(q);

    for(int i=0; i<n; i++){
        cin >> s;
        if(s == "push_front"){
            int x;
            cin >> x;
            push_L(x,q);
        }
        else if(s == "push_back"){
            int x;
            cin >> x;
            push_R(x,q);
        }
        else if(s == "pop_front") pop_L(q);
        else if(s == "pop_back") pop_R(q);
        else if(s == "size") cout << Size << "\n";
        else if(s == "empty"){
            if(Size == 0) cout << "1\n";
            else cout << "0\n";
        }
        else if(s == "front") print_L(q);
        else if(s == "back") print_R(q);
    }
}
