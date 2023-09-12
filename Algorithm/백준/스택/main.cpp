#include <iostream>

using namespace std;

int Size; //���� ũ��
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
    Size = 0;
    return S;
}

//���� �ֱ�
void Push(int x, Stack S){
    Stack A = new struct Node;
    A -> Next = S -> Next;
    S -> Next = A;
    A -> data = x;
    Size++;
}

//���� ���� ���
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

//���� ���
void Top(Stack S){
    if(Size == 0) cout << "-1" << "\n";
    else{
        cout << (S -> Next) -> data << "\n";
    }
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
