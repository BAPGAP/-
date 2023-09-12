#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;

int v[100001][2];

void make_tree(int in_L,int in_R,int post_L,int post_R){
    int parent = postorder[post_R];
    int pos;
    for(int i=in_L; i<=in_R; i++){
        if(parent == inorder[i]){
            pos = i;
            break;
        }
    }

    int in_L_L = in_L;
    int in_L_R = pos - 1;
    int in_R_L = pos + 1;
    int in_R_R = in_R;

    int post_L_L = post_L;
    int post_L_R = post_L + pos - in_L - 1;
    int post_R_L = post_L_R + 1;
    int post_R_R = post_R - 1;


    if(in_L_L == in_L_R) v[parent][0] = inorder[in_L_L];
    else if(in_L_L < in_L_R){
        v[parent][0] = postorder[post_L_R];
        make_tree(in_L_L,in_L_R,post_L_L,post_L_R);
    }
    if(in_R_L == in_R_R) v[parent][1] = inorder[in_R_L];
    else if(in_R_L < in_R_R){
        v[parent][1] = postorder[post_R_R];
        make_tree(in_R_L,in_R_R,post_R_L,post_R_R);
    }
}

void preorder(int x){
    cout << x << " ";
    if(v[x][0] != -1) preorder(v[x][0]);
    if(v[x][1] != -1) preorder(v[x][1]);
}

int main()
{
    int n;
    cin >> n;
    inorder.resize(n);
    postorder.resize(n);
    for(int i=0; i<n; i++){
        v[i+1][0] = -1;
        cin >> inorder[i];
    }
    for(int i=0; i<n; i++){
        v[i+1][1] = -1;
        cin >> postorder[i];
    }
    int node = postorder[n-1];
    make_tree(0,n-1,0,n-1);
    preorder(node);
}
