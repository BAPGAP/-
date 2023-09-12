#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


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

void push_R(int x, Deque Q){
    Deque A = new struct typedeq;
    A -> data = x;
    A -> R = Q -> R;
    A -> L = Q;
    (Q -> R) -> L = A;
    Q -> R = A;
    Size++;
}

int pop_L(Deque Q){
    int x = (Q -> L) -> data;
    Deque tmp = Q -> L;
    ((Q -> L) -> L) -> R = Q;
    Q -> L = (Q -> L) -> L;
    delete tmp;
    Size--;
    return x;
}

int pop_R(Deque Q){
    int x = (Q -> R) -> data;
    Deque tmp = Q -> R;
    ((Q -> R) -> R) -> L = Q;
    Q -> R = (Q -> R) -> R;
    delete tmp;
    Size--;
    return x;
}


char str[300000];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int m;
        cin >> m;
        Deque q = makeDeq(q);
        cin >> str;
        char *ptr = strtok(str, ",[]");
        while (ptr != NULL)
        {
            int tmp = atoi(ptr);
            push_R(tmp, q);
            ptr = strtok(NULL, ",[]");
        }
        int rev = 1;
        int isok = 1;

        for(int j=0; j<s.size(); j++){
            if(s[j] == 'R'){
                if(rev) rev = 0;
                else rev = 1;
            }
            else if(s[j] == 'D' && rev == 1){
                if(Size == 0){isok = 0; break;}
                else{
                    pop_L(q);
                }
            }
            else if(s[j] == 'D' && rev == 0){
                if(Size == 0){isok = 0; break;}
                else{
                    pop_R(q);
                }
            }
        }

        if(isok){
            if(Size == 0){
                cout << "[]" << "\n";
            }
            else if(rev){
                cout << "[";
                while(1){
                    if(Size == 1){
                        cout << pop_L(q) << "]\n";
                        break;
                    }
                    else{
                        cout << pop_L(q) << ",";
                    }
                }
            }
            else{
                cout << "[";
                while(1){
                    if(Size == 1){
                        cout << pop_R(q) << "]\n";
                        break;
                    }
                    else{
                        cout << pop_R(q) << ",";
                    }
                }
            }
        }
        else cout << "error" << "\n";
    }
}
