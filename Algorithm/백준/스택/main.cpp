#include <iostream>

using namespace std;

int Size; //스택 크기
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
    Size = 0;
    return S;
}

//정수 넣기
void Push(int x, Stack S){
    Stack A = new struct Node;
    A -> Next = S -> Next;
    S -> Next = A;
    A -> data = x;
    Size++;
}

//정수 빼고 출력
void Pop(Stack S){
    if(Size == 0) cout << "-1" << "\n";
    else{
        cout << (S -> Next) -> data << "\n";
        Stack tmp = S -> Next;
        S -> Next = (S -> Next) -> Next;
        delete tmp;
        Size--;
    }
}

//정수 출력
void Top(Stack S){
    if(Size == 0) cout << "-1" << "\n";
    else{
        cout << (S -> Next) -> data << "\n";
    }
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
    string s;
    Stack head = makeS();
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s == "push"){
            cin >> x;
            Push(x,head);
        }
        else if(s == "pop"){
            Pop(head);
        }
        else if(s == "size"){
            cout << Size << "\n";
        }
        else if(s == "empty"){
            if(Size == 0) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if(s == "top"){
            Top(head);
        }
    }
}
