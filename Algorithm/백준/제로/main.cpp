#include <iostream>

using namespace std;

int Sum = 0;
typedef struct Node* Stack; //Node ������ Ÿ���� ��Ÿ���� Stack

struct Node{
    int data;
    Stack Next;
};

//head�� ����� �Լ�
Stack makeS(){
    Stack S = new struct Node; //����ü �����Ҵ� �Ҷ� "struct"�� �ٿ���� ��
  //struct Node* S = new struct Node;
    S -> Next = NULL;
    return S;
}

//0 �ƴҶ�
void Push(int x, Stack S){
    Stack A = new struct Node;
    A -> Next = S -> Next;
    S -> Next = A;
    A -> data = x;
    Sum += x;
}

//0�϶�
void Pop(Stack S){
    Sum -= (S -> Next) -> data;
    Stack tmp = S -> Next;
    S -> Next = (S -> Next) -> Next;
    delete tmp;
}

//�޸� ����
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
