#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int x[100001];
int y[100001];
long double PI = 3.14159265358979;
long double gob[100001];

struct noname{
    long double ang;
    long double p;
};

noname A[100001];

long double tree[400001];

long double init(int node,int L,int R){
    if(L == R) return tree[node] = gob[L];
    return tree[node] = init(node*2,L,(L+R)/2) * init(node*2+1,(L+R)/2+1,R);
}

long double sum(int node,int L,int R,int X,int Y){
    if(R < X || Y < L) return 1;
    if(X <= L && R <= Y) return tree[node];
    return sum(node*2,L,(L+R)/2,X,Y) * sum(node*2+1,(L+R)/2+1,R,X,Y);
}

bool compare(noname n1, noname n2){
    return n1.ang < n2.ang;
}


int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x[i];
        }
        for(int i=0; i<n; i++){
            cin >> y[i];
        }

        for(int i=0; i<n; i++){
            cin >> A[i].p;
        }

        int a,b;

        cin >> a >> b;

        for(int i=0; i<n; i++){
            A[i].ang = atan2(y[i] - b,x[i] - a) * 180 / PI;
            if(A[i].ang < 0) A[i].ang += 360;
        }

        sort(A, A+n, compare);

        long double imp = 1;

        for(int i=0; i<n; i++){
            gob[i] = 1 - A[i].p;
            imp *= gob[i];
        }

        init(1,0,n-1);

        int pos1 = 0;
        int pos2 = 0;
        long double tmp;
        long double Answer = 1;

        for(int i=0; i<n; i++){
            pos1 = i;
            while(1){
                tmp = A[pos2].ang - A[pos1].ang;
                if(tmp < 0) tmp += 360;
                if(tmp > 180) break;

                pos2++;
                pos2 = pos2 % n;

                if(pos2 == pos1) break;
            }

            if(pos1 == pos2) Answer -= A[i].p;
            else{
                if(pos1 == 0) pos1 = n;

                if(pos2 == pos1 - 1) Answer -= A[i].p * gob[pos2];
                else if(pos2 > pos1 - 1){
                    Answer -= A[i].p * sum(1,0,n-1,0,pos1-1) * sum(1,0,n-1,pos2,n-1);
                }
                else{
                    Answer -= A[i].p * sum(1,0,n-1,pos2,pos1-1);
                }
            }
        }

        Answer -= imp;

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
