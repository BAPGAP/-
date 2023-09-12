#include <iostream>

using namespace std;

typedef struct tree* Tree;

struct tree{
    int data;
    Tree L;
    Tree R;
};

Tree makehead(int x){
    Tree T = new struct tree;
    T -> data = x;
    T -> L = NULL;
    T -> R = NULL;
    return T;
}

void init(Tree head,int x){
    while(1){
        if(head -> data == x) break;
        else if(head -> data < x){
            if(head -> R == NULL){
                Tree T = new struct tree;
                T -> data = x;
                T -> L = NULL;
                T -> R = NULL;
                head -> R = T;
                break;
            }
            else{
                head = head -> R;
            }
        }
        else if(head -> data > x){
            if(head -> L == NULL){
                Tree T = new struct tree;
                T -> data = x;
                T -> L = NULL;
                T -> R = NULL;
                head -> L = T;
                break;
            }
            else{
                head = head -> L;
            }
        }
    }
}

void check(Tree head,int x){
    if(head -> data == x){
        cout << "1\n";
        return;
    }
    if(head -> data > x){
        if(head -> L == NULL){
            cout << "0\n";
            return;
        }
        check(head -> L,x);
    }
    if(head -> data < x){
        if(head -> R == NULL){
            cout << "0\n";
            return;
        }
        check(head -> R,x);
    }
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int x;
    cin >> x;

    Tree head = makehead(x);

    for(int i=1; i<n; i++){
        cin >> x;
        init(head,x);
    }
    //트리에 저장

    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> x;
        check(head,x);
    }
}
