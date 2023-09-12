#include <iostream>

using namespace std;

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

//���� �ֱ�
void Push(int x, Stack S){
    Stack A = new struct Node;
    A -> Next = S -> Next;
    S -> Next = A;
    A -> data = x;
}

//���� ��
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
