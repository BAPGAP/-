#include <iostream>
#include <vector>

using namespace std;

int a[501][501];
int tree[2][501][1001]; //tree_row[x][y][]�� y��° ����Ʈ�� x = 0 : row�� ����Ʈ�� // x = 1 : col�� ����Ʈ��


//a[0] ~ a[n-1]�� ���׸�Ʈ Ʈ���� �������!
//tree[n] ~ tree[2n-1]�� a[0] ~ a[n-1]�� ������ ��

void make_tree(int type,int num,int n){ //row or col? , which number of? ,Ʈ�� ���� �迭 ������
    for(int i=n-1; i>0; i--){
        tree[type][num][i] = max(tree[type][num][i << 1], tree[type][num][i << 1 | 1]);
    }
}

int gap(int type,int num,int n,int l,int r){ // ���� [ l , r ) �� ���̴�.
    int mx = 0;
    for(l += n,r += n; l < r; l >>= 1,r >>= 1){ // l < r�� ���� ������ l,r�� 2�� ����, �ʱ� l , r ���� n�� �����ش�
        if(l & 1) mx = max(mx,tree[type][num][l++]); //l�� Ȧ���϶�
        if(r & 1) mx = max(mx,tree[type][num][--r]); //r�� Ȧ���϶�
    }
    return mx;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            tree[0][i][j+m] = a[i][j];
            tree[1][j][i+n] = a[i][j];
        }
        make_tree(0,i,m); //make row segtree
    }
    for(int j=0; j<m; j++){
        make_tree(1,j,n); //make col segtree
    }

    int t;
    cin >> t;
    int Answer;
    int x,y,r,c,k,d;

    for(int tc=0; tc<t; tc++){
        Answer = 0;
        cin >> x >> y >> r >> c >> k >> d;
        x--;
        y--;
        int cur[1100] = {0};
        int slice,len;

        if(d == 1){ //��
            for(int i=x; i<x+(k-1)+r; i++){
                cur[i - x] = gap(0,i,m,y,y+c);
            }
            slice = r; //r���� ��� Ȯ��
            len = k+r-1; //��ü����
        }
        else if(d == 2){ //��
            for(int i=x-k+1; i<x+r; i++){
                cur[i-x+k-1] = gap(0,i,m,y,y+c);
            }
            slice = r;
            len = r+k-1;
        }
        else if(d == 3){ //��
            for(int i=y; i<y+(k-1)+c; i++){
                cur[i - y] = gap(1,i,n,x,x+r);
            }
            slice = c;
            len = k+c-1;
        }
        else if(d == 4){ //��
            for(int i=y-k+1; i<y+c; i++){
                cur[i-y+k-1] = gap(1,i,n,x,x+r);
            }
            slice = c;
            len = k+c-1;
        }

        int cur_max[2*slice-1];
        int pos1 = 0;

        while(pos1 < k){
            cur_max[slice - 1] = cur[pos1 + slice - 1];
            for(int i=1; i<slice; i++){
                cur_max[slice - 1 - i] = max(cur_max[slice - 1 - i + 1],cur[slice - 1 - i + pos1]);
                cur_max[slice - 1 + i] = max(cur_max[slice - 1 + i - 1],cur[slice - 1 + i + pos1]);
            }

            int tmp = pos1;
            while(pos1 < min(k,tmp + slice)){
                Answer ^= max(cur_max[pos1 - tmp],cur_max[pos1 - tmp + slice - 1]);
                pos1++;
            }
        }

        cout << Answer << "\n";
    }
}
