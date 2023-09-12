#include <iostream>

using namespace std;

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

//정수 넣기
void Push(int x, Stack S){
    Stack A = new struct Node;
    A -> Next = S -> Next;
    S -> Next = A;
    A -> data = x;
}

//정수 빼
void Pop(Stack S){
    Stack tmp = S -> Next;
    S -> Next = (S -> Next) -> Next;
    delete tmp;
}

int a[1000001];
int b[1000001];

int main()
{
    int n;
    cin >> n;
    for(int i=n; i>0; i--){
        cin >> a[i];
    }
    Stack head = makeS();

    for(int i=1; i<=n; i++){
        if(head -> Next == NULL){
            b[i] = -1;
            Push(a[i],head);
        }
        else if((head -> Next) -> data > a[i]){
            b[i] = (head -> Next) -> data;
            Push(a[i],head);
        }
        else{
            while(1){
                if(head -> Next == NULL){
                    b[i] = -1;
                    Push(a[i],head);
                    break;
                }
                else if((head -> Next) -> data > a[i]){
                    b[i] = (head -> Next) -> data;
                    Push(a[i],head);
                    break;
                }
                else{
                    Pop(head);
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << b[i] << " ";
    }
}
