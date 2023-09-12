#include <iostream>

using namespace std;

int Sum = 0;
typedef struct Node* Stack; //Node 포인터 타입을 나타내는 Stack

struct Node{
    int data;
    Stack Next;
};

//head를 만드는 함수
Stack makeS(){
    Stack S = new struct Node; //구조체 동적할당 할때 "struct"를 붙여줘야 함
  //struct Node* S = new struct Node;
    S -> Next = NULL;
    return S;
}

//0 아닐때
void Push(int x, Stack S){
    Stack A = new struct Node;
    A -> Next = S -> Next;
    S -> Next = A;
    A -> data = x;
    Sum += x;
}

//0일때
void Pop(Stack S){
    Sum -= (S -> Next) -> data;
    Stack tmp = S -> Next;
    S -> Next = (S -> Next) -> Next;
    delete tmp;
}

//메모리 해제
void Del(Stack S){
    while(1){
        if(S -> Next == NULL){
            delete S;
            break;
        }
        else{
            Stack tmp = S -> Next;
            S -> Next = (S -> Next) -> Next;
            delete tmp;
        }
    }
}


int main()
{
    int n;
    int x;
    cin >> n;
    Stack head = makeS();
    for(int i=0; i<n; i++){
        cin >> x;
        if(x == 0){
            Pop(head);
        }
        else{
            Push(x,head);
        }
    }
    cout << Sum << endl;
    Del(head);
}
