#include <vector>

using namespace std;

int lazy[1001][4004] = {0};
vector<vector<int>> B;

void update(int row,int node,int L,int R,int l,int r,int gap){
    if(r < L || R < l) return;
    else if(l <= L && R <= r){
        lazy[row][node] += gap;
        return;
    }
    else{
        int M = (L+R)>>1;
        update(row,2*node,L,M,l,r,gap);
        update(row,2*node+1,M+1,R,l,r,gap);
        return;
    }
}

int gap(int row,int node,int L,int R){
    if(lazy[row][node] != 0 && L != R){
        lazy[row][node*2] += lazy[row][node];
        lazy[row][node*2+1] += lazy[row][node];
    }
    int M = (L+R)>>1;
    if(L == R){
        if(lazy[row][node] + B[row][L] > 0) return 1;
        else return 0;
    }
    else return gap(row,2*node,L,M) + gap(row,2*node+1,M+1,R);
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    B = board;
    //°¢ tree´Â 0 ~ m-1

    for(int i=0; i<skill.size(); i++){
        int carry = 1;
        if(skill[i][0] == 1) carry = -1;
        carry *= skill[i][5];
        for(int j=skill[i][1]; j<=skill[i][3]; j++){
            update(j,1,0,m-1,skill[i][2],skill[i][4],carry);
        }
    }
    int answer = 0;
    for(int i=0; i<n; i++){
        answer += gap(i,1,0,m-1);
    }
    return answer;
}
