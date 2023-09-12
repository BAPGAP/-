#include <iostream>
#include <algorithm>

using namespace std;

int Answer;

int x[100001][2];
int y[100001][2];
int go[100001];
int tree[400010];
int lazy[400010];

int init(int node,int L,int R){
    if(L == R){
        lazy[node] = 0;
        return tree[node] = go[L];
    }
    return tree[node] = max(init(node*2,L,(L+R)/2),init(node*2+1,(L+R)/2+1,R));
}

void edit(int node,int L,int R,int l,int r,int data1,int l2,r2){ //일단 빚만 주기
    if(lazy[node] != 0){ //빚있었으면 물려주고 청산
        int bit = lazy[node];
        tree[node] += bit;
        if(L != R){
            tree[node*2] += bit;
            tree[node*2+1] += bit;
        }
        lazy[node] = 0;
    }

    if(R < l || r < L) return;
    else if(l <= L && R <= r){ //빚을 딱 받아야됨
        lazy[node] += data;
        return;
    }
    else{ //걸친경우
        int M = (L+R)/2;
        edit(2*node,L,M,l,r,data);
        edit(2*node+1,M+1,R,l,r,data);
    }
}

int pay(int node,int L,int R){ //빚 청산하기
    if(lazy[node] == 0){
        int M = (L+R)/2;
        return tree[node] = max(pay(node*2,L,M),pay(node*2+1,M+1,R));
    }
    else{
        int bit = lazy[node];
        tree[node] += bit;
        if(L != R){
            tree[node*2] += bit;
            tree[node*2+1] += bit;
        }
        lazy[node] = 0;
        return tree[node];
    }
}

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    Answer = 0;
	    int n;
	    cin >> n;
	    int a,b,c;
	    int cnt = 0;
	    for(int i=0; i<n; i++){
            cin >> a >> b >> c;
            x[a][0] = b;
            x[a][1] = c;
            y[b][0] = a;
            y[b][1] = c;
            if(c == 0) cnt++;
	    }
	    go[0] = cnt;

	    int tmp;
	    for(int i=1; i<=n; i++){
            tmp = 1;
            if(x[i][1] == 0){
                tmp = -1;
            }
            go[i] = go[i-1] + tmp;
	    }

	    init(1,0,n);

	    Answer = max(Answer,tree[1]);

        for(int i=1; i<=n; i++){
            if(y[i][1] == 0){
                edit(1,0,n,0,y[i][0]-1,-1);
                edit(1,0,n,y[i][0],n,1);
                //일단 빚만 줬음
                pay(1,0,n); //0~n까지 다 바뀜
            }
            else{
                edit(1,0,n,0,y[i][0]-1,1);
                edit(1,0,n,y[i][0],n,-1);
                pay(1,0,n);
            }
            Answer = max(Answer,tree[1]);
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
