#include <iostream>
#include <algorithm>

using namespace std;
typedef struct rec R;
int k;
int Answer;

struct rec{
    long long x1,y1,x2,y2;
};

bool compare(rec a, rec b){
   return (a.x2 - a.x1) * (a.y2 - a.y1) < (b.x2 - b.x1) * (b.y2 - b.y1);
}

bool inc(R a,R b){ //a가 b를 포함?
    if(a.x1 > b.x1) return false;
    if(a.y1 > b.y1) return false;
    if(b.x2 > a.x2) return false;
    if(b.y2 > a.y2) return false;
    return true;
}


R r[5001];
int cnt[5001];

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n,m,k;
	    cin >> n >> m >> k;
        Answer = 0;
	    for(int i=0; i<k; i++){
            cnt[i] = 0;
            cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
	    }
        sort(r,r+k,compare);
        cnt[0] = 1;

        for(int i=1; i<k; i++){
            for(int j=0; j<i; j++){
                if(inc(r[i],r[j])){
                    cnt[i] = max(cnt[i],cnt[j]);
                }
            }
            cnt[i]++;
            if(cnt[i] > Answer) Answer = cnt[i];
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
