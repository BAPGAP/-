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

//정수 빼기
void Pop(Stack S){
    Stack tmp = S -> Next;
    S -> Next = (S -> Next) -> Next;
    delete tmp;
}

char c[1000001];
int a[100001];

int ok = 1;

int main()
{
    int n;
    cin >> n;
    Stack head = makeS();
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int cnt = 1;
    int cnt_a = 0;
    int cnt_c = 0;

    while(1){
        if(cnt_a == n) break;

        if(a[cnt_a] >= cnt){
            Push(cnt, head);
            c[cnt_c] = '+';
            cnt_c++;
            cnt++;
        }
        else{
            if(a[cnt_a] != (head -> Next) -> data){ok = 0; break;}
            Pop(head);
            c[cnt_c] = '-';
            cnt_c++;
            cnt_a++;
        }
    }
    if(ok == 1){
        for(int i=0; i<cnt_c; i++){
            cout << c[i] << "\n";
        }
    }
    else cout << "NO" << endl;
}
