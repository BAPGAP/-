#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int Answer;
vector<pair<int,int> > v;
int tree[201000];
int lazy[201000];
char s[50100];

void setLazy(int node, int L, int R)
{
    int val = lazy[node];
    lazy[node] = 0;
    tree[node] += val;
    if (L != R)
    {
        lazy[node * 2] += val;
        lazy[node * 2 + 1] += val;
    }
}

void update(int node, int L, int R, int i, int j, int val) //구간 i ~ j 에  +val 만큼씩
{
    if (lazy[node] != 0) setLazy(node, L, R);

    if (j < L || R < i) return;
    if (i <= L && R <= j)
    {
        tree[node] += val;
        if (L != R)
        {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }

        return;
    }

    update(node * 2, L, (L + R) / 2, i, j, val);
    update(node * 2 + 1, (L + R) / 2 + 1, R, i, j, val);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int ten[10] = {1,10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));

        int n,k,m;

        cin >> n >> k >> m;
        scanf("%s",s);

        int sum = 0;
        int pos = k-1;

        for(int i=0; i<n; i++){
            sum += ten[pos] * (s[i] - '0');
            pos--;
            if(pos < 0){
                v.push_back(make_pair(sum,n+i));
                for(int j=i; j > i-k; j--){
                    if(s[j] == '1') continue;
                    v.push_back(make_pair(sum + ten[i-j] * (1 - (s[j] - '0')),j));
                }
                sum = (sum % ten[k-1]) * 10;
                pos = 0;
            }
        }

        sort(v.begin(),v.end());

        int pos1 = 0;
        int pos2 = 0;

        while(pos2 < v.size()){
            if(v[pos2].first - v[pos1].first > m) break;

            if(v[pos2].second >= n){
                update(1,0,n-1,v[pos2].second-n-k+1,v[pos2].second-n,-1);
                update(1,0,n-1,0,n-1,1);
            }
            else update(1,0,n-1,v[pos2].second,v[pos2].second,1);
            pos2++;
        }

        Answer = tree[1];

        for(int i=1; i<v.size(); i++){

            //pos1 삭제
            if(v[pos1].second >= n){
                update(1,0,n-1,v[pos1].second-n-k+1,v[pos1].second-n,1);
                update(1,0,n-1,0,n-1,-1);
            }
            else update(1,0,n-1,v[pos1].second,v[pos1].second,-1);

            pos1 = i;

            if(v[pos2].first - v[pos1].first > m) continue;

            //pos2 추가
            while(pos2 < v.size()){
                if(v[pos2].first - v[pos1].first > m) break;

                if(v[pos2].second >= n){
                    update(1,0,n-1,v[pos2].second-n-k+1,v[pos2].second-n,-1);
                    update(1,0,n-1,0,n-1,1);
                }
                else update(1,0,n-1,v[pos2].second,v[pos2].second,1);
                pos2++;
            }

            Answer = max(Answer,tree[1]);

            if(pos2 == v.size()) break;
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
		v.clear();
	}

	return 0;
}
