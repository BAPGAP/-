#include <iostream>

using namespace std;

struct N{
    struct N* next;
    int start;
    int fin;
};

int main()
{
    struct N* head;
    int n;
    int x,y;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        struct N* node = new N;
        node -> start = x;
        node -> fin = y;
        head -> next = node;
    }
}
