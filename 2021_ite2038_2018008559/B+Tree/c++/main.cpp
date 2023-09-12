#include <iostream>
#include <cstdio>

using namespace std;

int max_degree;
int min_key; //각 node는 최소 min_key만큼 key를 가져야함
typedef struct node* N;
N root = NULL;

struct node{
    int m; // # key
    bool isleaf; //leaf or nonleaf
    int *key;
    int **value;
    N *left_child_node;
    N rightnode; //leaf면 오른쪽 형제가 저장되고, leaf가 아니면 가장 오른쪽 자식이 저장된다.
};

N make_node(int k,int v,bool b){

    N T = new struct node;
    T -> m = 1;
    T -> isleaf = b;
    T -> key = new int[max_degree+1];
    T -> key[0] = k;
    if(b){
        T -> value = new int*[max_degree+1];
        for(int i=0; i<max_degree+1; i++){
            T -> value[i] = new int;
        }
        *(T -> value[0]) = v;
    }
    else{
        T -> left_child_node = new struct node*[max_degree+1];
        for(int i=0; i<max_degree+1; i++){
            T -> left_child_node[i] = NULL;
        }
    }
    T -> rightnode = NULL;
    return T;
}

void split(N parent,N child){ //if child is full
    int pos = max_degree/2;

    N new_node = make_node(0,0,child -> isleaf);

    child -> m = pos;

    if(child -> isleaf){
        for(int i=pos; i<max_degree; i++){
            new_node -> key[i-pos] = child -> key[i];
            new_node -> value[i-pos] = child -> value[i];
        }
        new_node -> m = max_degree - pos;
        new_node -> rightnode = child -> rightnode;
        child -> rightnode = new_node;
    }
    else{
        for(int i=pos+1; i<max_degree; i++){
            new_node -> key[i-pos-1] = child -> key[i];
            new_node -> left_child_node[i-pos-1] = child -> left_child_node[i];
        }
        new_node -> m = max_degree - pos - 1;
        new_node -> rightnode = child -> rightnode;
        child -> rightnode = child -> left_child_node[pos];
    }

    int k = child -> key[pos];

    if(parent == NULL){ //new root
        //새로 생기는 루트는 무조건 non leaf
        N new_root = make_node(k,0,false);
        new_root -> left_child_node[0] = child;
        new_root -> rightnode = new_node;
        root = new_root;
        return;
    }

    //child가 leaf든 아니든 부모는 무조건 nonleaf

    if(k > parent -> key[parent -> m - 1]){
        parent -> key[parent -> m] = child -> key[pos];
        parent -> rightnode = new_node;
        parent -> left_child_node[parent -> m] = child;
        parent -> m += 1;
        return;
    }

    for(int i=parent -> m; i>0; i--){
        if(k > parent -> key[i-1]){
            parent -> key[i] = child -> key[pos];
            parent -> left_child_node[i] = child;
            parent -> left_child_node[i+1] = new_node;
            parent -> m += 1;
            return;
        }
        parent -> key[i] = parent -> key[i-1];
        parent -> left_child_node[i] = parent -> left_child_node[i-1];
    }

    parent -> key[0] = child -> key[pos];
    parent -> left_child_node[0] = child;
    parent -> left_child_node[1] = new_node;
    parent -> m += 1;
    return;
}

N insertion(N T,int k,int v){
    if(T -> isleaf){
        for(int i=T -> m; i>0; i--){
            if(k > T -> key[i-1]){
                T -> key[i] = k;
                *(T -> value[i]) = v;
                break;
            }
            T -> key[i] = T -> key[i-1];
            T -> value[i] = T -> value[i-1];
            if(i==1){
                T -> key[0] = k;
                *(T -> value[0]) = v;
            }
        }
        T -> m += 1;
        return T;
    }
    else{
        N next = NULL;
        for(int i=0; i<T -> m; i++){
            if(k < T -> key[i]){
                next = T -> left_child_node[i];
                break;
            }
        }
        if(next == NULL) next = T -> rightnode;

        next = insertion(next,k,v);

        if(next -> m == max_degree){
            split(T,next);
        }
        return T;
    }
}

void in(N T,int k,int v){
    T = insertion(T,k,v);
    if(T -> m == max_degree){
        split(NULL,T);
    }
}

void print(N T){
    if(T == NULL) cout << "nothing!!\n";
    else{
        cout << "size : " << T -> m << "\n";
        if(T -> isleaf){
            cout << "i am leaf\n";
            for(int i=0; i<T -> m; i++){
                cout << "key : " << T -> key[i] << " value : " << *(T -> value[i]) << "   ";
            }
            cout << "\n";
            if(T -> rightnode == NULL) cout << "i dont have sibling\n";
            else cout << "i have sibling and it starts with " << T -> rightnode -> key[0] << "\n";
        }
        else{
            cout << "i am not leaf\n";
            for(int i=0; i<T -> m; i++){
                cout << "key : " << T -> key[i] << "   ";
            }
            cout << "\n";
            for(int i=0; i<T -> m; i++){
                print(T -> left_child_node[i]);
            }
            print(T -> rightnode);
        }
    }
}

void serch(N T,int k){
    if(T -> isleaf){
        for(int i=0; i<T -> m; i++){
            if(T -> key[i] == k){
                cout << T -> value[i] << "\n";
                return;
            }
        }
        cout << "NOT FOUND\n";
    }
    else{
        N next = NULL;
        for(int i=0; i<T -> m; i++){
            if(next == NULL && k < T -> key[i]) next = T -> left_child_node[i];
            cout << T -> key[i] << ", ";
        }
        if(next == NULL) next = T -> rightnode;
        serch(next,k);
    }
}

N findpointer(N T,int k){
    if(T -> isleaf){
        return T;
    }
    else{
        N next = NULL;
        for(int i=0; i<T -> m; i++){
            if(k < T -> key[i]){
                next = T -> left_child_node[i];
                break;
            }
        }
        if(next == NULL) next = T -> rightnode;
        return findpointer(next,k);
    }
}

void range_serch(N T,int x,int y){
    N L = findpointer(T,x);
    N R = findpointer(T,y);

    for(int i=0; i<L -> m; i++){
            if(x <= L -> key[i] && L -> key[i] <= y) cout << L -> key[i] << "," << L -> value[i] << "\n";
    }

    if(L == R) return;

    L = L -> rightnode;

    while(L != R){
        for(int i=0; i<L -> m; i++){
            cout << L -> key[i] << "," << L -> value[i] << "\n";
        }
        L = L -> rightnode;
    }

    for(int i=0; i<L -> m; i++){
            if(x <= L -> key[i] && L -> key[i] <= y) cout << L -> key[i] << "," << L -> value[i] << "\n";
    }
}

N balance(N parent,N child,int pos){
    if(child -> m >= min_key) return parent; //굳이 조정 할 필요 없음
    if(child -> isleaf){
        if(pos > 0 && parent -> left_child_node[pos-1] -> m > min_key){ //왼쪽 형제에서 땡겨올수 있음
            N sibling = parent -> left_child_node[pos-1];
            sibling -> m -= 1;
            for(int i=child -> m; i>0; i--){
                child -> key[i] = child -> key[i-1];
                child -> value[i] = child -> value[i-1];
            }
            child -> key[0] = sibling -> key[sibling -> m];
            child -> value[0] = sibling -> value[sibling -> m];
            child -> m += 1;
            parent -> key[pos-1] = child -> key[0];
            return parent;
        }
        if(pos < parent -> m){
            N sibling;
            if(pos == parent -> m - 1) sibling = parent -> rightnode;
            else sibling = parent -> left_child_node[pos+1];
            if(sibling -> m > min_key){
                child -> key[child -> m] = sibling -> key[0];
                child -> value[child -> m] = sibling -> value[0];
                child -> m += 1;
                for(int i=1; i<sibling -> m; i++){
                    sibling -> key[i-1] = sibling -> key[i];
                    sibling -> value[i-1] = sibling -> value[i];
                }
                sibling -> m -= 1;
                parent -> key[pos] = sibling -> key[0];
                return parent;
            }
        }
        //형제들이 모두 거지면 merge해야됨
        if(pos > 0){ //왼쪽 형제가 있으면 우선적으로 merge
            N sibling = parent -> left_child_node[pos-1];
            for(int i=0; i<child -> m; i++){
                sibling -> key[sibling -> m + i] = child -> key[i];
                sibling -> value[sibling -> m + i] = child -> value[i];
            }
            sibling -> m += child -> m;
            sibling -> rightnode = child -> rightnode;
            for(int i=pos; i<parent -> m - 1; i++){
                parent -> key[i] = parent -> key[i+1];
                parent -> left_child_node[i] = parent -> left_child_node[i+1];
            }
            if(sibling -> rightnode != NULL) parent -> key[pos - 1] = sibling -> rightnode -> key[0];
            if(pos == parent -> m) parent -> rightnode = sibling;
            parent -> m -= 1;
            return parent;
        }
        else{
            N sibling;
            if(parent -> m == 1) sibling = parent -> rightnode;
            else sibling = parent -> left_child_node[1];

            for(int i=0; i<sibling -> m; i++){
                child -> key[child -> m + i] = sibling -> key[i];
                child -> value[child -> m + i] = sibling -> value[i];
            }
            child -> m += sibling -> m;
            child -> rightnode = sibling -> rightnode;

            for(int i=1; i<parent -> m - 1; i++){
                parent -> key[i] = parent -> key[i+1];
                parent -> left_child_node[i] = parent -> left_child_node[i+1];
            }
            parent -> m -= 1;
            if(parent -> m != 0) parent -> key[0] = child -> rightnode -> key[0];
            return parent;
        }
    }
    else{ //부모와 자식 모두 nonleaf
        if(pos > 0 && parent -> left_child_node[pos-1] -> m > min_key){ //왼쪽 자식에서 땡겨오기 가능
            N sibling = parent -> left_child_node[pos-1];
            sibling -> m -= 1;
            for(int i=child -> m; i>0; i--){
                child -> key[i] = child -> key[i-1];
                child -> left_child_node[i] = child -> left_child_node[i-1];
            }
            child -> key[0] = parent -> key[pos-1];
            child -> left_child_node[0] = sibling -> rightnode;
            child -> m += 1;
            parent -> key[pos-1] = sibling -> key[sibling -> m];
            sibling -> rightnode = sibling -> left_child_node[sibling -> m];
            return parent;
        }
        if(pos < parent -> m){
            N sibling;
            if(pos == parent -> m - 1) sibling = parent -> rightnode;
            else sibling = parent -> left_child_node[pos+1];
            if(sibling -> m > min_key){
                child -> key[child -> m] = parent -> key[pos];
                parent -> key[pos] = sibling -> key[0];
                child -> left_child_node[child -> m] = child -> rightnode;
                child -> rightnode = sibling -> left_child_node[0];
                child -> m += 1;
                sibling -> m -= 1;
                for(int i=0; i<sibling -> m; i++){
                    sibling -> key[i] = sibling -> key[i+1];
                    sibling -> left_child_node[i] = sibling -> left_child_node[i+1];
                }
                return parent;
            }
        }
        //빌려올수 없으면 merge
        if(pos > 0){
            N sibling = parent -> left_child_node[pos-1];
            sibling -> key[sibling -> m] = parent -> key[pos-1];
            sibling -> left_child_node[sibling -> m] = sibling -> rightnode;
            sibling -> m += 1;
            for(int i=0; i<child -> m; i++){
                sibling -> key[sibling -> m + i] = child -> key[i];
                sibling -> left_child_node[sibling -> m + i] = child -> left_child_node[i];
            }
            sibling -> m += child -> m;
            sibling -> rightnode = child -> rightnode;
            parent -> key[pos-1] = parent -> key[pos];
            parent -> m -= 1;
            for(int i=pos; i<parent -> m; i++){
                parent -> key[i] = parent -> key[i+1];
                parent -> left_child_node[i] = parent -> left_child_node[i+1];
            }
            if(pos > parent -> m) parent -> rightnode = sibling;
            return parent;
        }
        else{
            N sibling;
            if(parent -> m == 1) sibling = parent -> rightnode;
            else sibling = parent -> left_child_node[1];
            child -> key[child -> m] = parent -> key[0];
            child -> left_child_node[child -> m] = child -> rightnode;
            child -> m += 1;
            for(int i=0; i<sibling -> m; i++){
                child -> key[child -> m + i] = sibling -> key[i];
                child -> left_child_node[child -> m + i] = sibling -> left_child_node[i];
            }
            child -> m += sibling -> m;
            child -> rightnode = sibling -> rightnode;
            parent -> m -= 1;
            if(parent -> m == 0) return parent;

            parent -> key[0] = parent -> key[1];
            for(int i=1; i<parent -> m; i++){
                parent -> key[i] = parent -> key[i+1];
                parent -> left_child_node[i] = parent -> left_child_node[i+1];
            }
            return parent;
        }
    }
}

N deletion(N T,int k){
    if(T -> isleaf){
        bool isdel = false;
        for(int i=0; i<T -> m; i++){
            if(k == T -> key[i]){
                for(int j=i+1; j<T -> m; j++){
                    T -> key[j-1] = T -> key[j];
                    T -> value[j-1] = T -> value[j];
                }
                isdel = true;
                T -> m -= 1;
                break;
            }
        }
        if(!isdel) cout << "deletion failed : no key\n";
        return T;
    }
    else{
        N next = NULL;
        int pos = T -> m;
        for(int i=0; i<T-> m; i++){
            if(k < T -> key[i]){
                next = T -> left_child_node[i];
                pos = i;
                break;
            }
        }
        if(next == NULL) next = T -> rightnode;

        next = deletion(next,k);

        balance(T,next,pos);

        return T;
    }
}

void change(N T,N nl,int pos,int k){
    if(T -> isleaf){
        if(nl != NULL) nl -> key[pos] = T -> key[0];
        return;
    }
    else{
        N next = NULL;
        for(int i=0; i<T->m; i++){
            if(nl == NULL && k == T -> key[i]){
                nl = T;
                pos = i;
            }
            if(k < T -> key[i]){
                next = T -> left_child_node[i];
                break;
            }
        }
        if(next == NULL) next = T -> rightnode;
        change(next,nl,pos,k);
    }
}

N del(N T,int k){
    T = deletion(T,k);
    if(T -> m == 0 && !T -> isleaf) T = T -> left_child_node[0];
    change(T,NULL,0,k);
    return T;
}

int main()//int argc,char *argv[])
{
    /*
    FILE* file;

    if(argv[1][1] == 'c'){
        file = fopen(argv[2],"w");
    }
    else if(argv[1][1] == 'i'){

    }
    */


    cin >> max_degree;
    min_key = (max_degree-1)/2;
    while(1){
        int type; // 1 : insert, 2 : delete, 3 : serch, 4 : range serch, 5 : print
        cin >> type;
        if(type == 1){
            int k,v;
            cin >> k >> v;
            if(root == NULL) root = make_node(k,v,true);
            else in(root,k,v);
        }
        else if(type == 2){
            int k;
            cin >> k;
            if(root == NULL || root -> m == 0) cout << "no node!\n";
            else root = del(root,k);
        }
        else if(type == 3){
            int k;
            cin >> k;
            if(root == NULL) cout << "no node!\n";
            else serch(root,k);
        }
        else if(type == 4){
            int x,y;
            cin >> x >> y;
            if(root == NULL) cout << "no node!\n";
            else range_serch(root,x,y);
        }
        else if(type == 5) print(root);
    }
}
