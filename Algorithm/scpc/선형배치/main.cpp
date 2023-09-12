#include <iostream>
#include <cmath>
#include <random>
#include <vector>

using namespace std;

vector<int> v[101];

// under 9
int d[10];
int d_check[10];
int under_answer[10];
int u_answer;

int under_gap(int n){
    int ok[10];

    for(int i=0; i<n; i++){
        ok[d[i]] = i;
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<v[i].size(); j++){
            sum += abs(ok[i] - ok[v[i][j]]);
        }
    }
    return sum/2;
}

void back_tracking(int n,int x){
    if(x == n){
        int tmp = under_gap(n);
        if(u_answer > tmp){
            for(int i=0; i<n; i++){
                under_answer[i] = d[i];
            }
            u_answer = tmp;
        }
        return;
    }

    for(int i=0; i<n; i++){
        if(d_check[i] == 0){
            d[x] = i;
            d_check[i] = 1;
            back_tracking(n,x+1);
            d_check[i] = 0;
        }
    }
    return;
}

// under 9

// up 9

mt19937_64 seed(428);
uniform_int_distribution<int> range(0, 2000);

int Answer;
int up_answer[101];

int len_hap(int* A,int n){
    int ok[n+1];

    for(int i=0; i<n; i++){
        ok[A[i]] = i;
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<v[i].size(); j++){
            sum += abs(ok[i] - ok[v[i][j]]);
        }
    }
    return sum/2;
}

void rfs(int n,int x){ //random first serch ㅋㅋ
    int check[n+1] = {0};
    int tmp_answer[n+1];
    tmp_answer[0] = x;
    int tmp_cnt = 1;
    check[x] = 1;
    int tmp = x;

    while(1){
        int degree = v[tmp].size(); //연결되어있는 정점의 수
        int letsrandom[degree];
        int cnt = 0;
        for(int i=0; i<degree; i++){
            if(check[v[tmp][i]] == 0) letsrandom[cnt++] = v[tmp][i];
        }
        if(cnt == 0){
            break;
        }

        tmp = range(seed) % cnt; //랜덤으로 정점 추가
        tmp = letsrandom[tmp];
        check[tmp] = 1;
        tmp_answer[tmp_cnt] = tmp;
        tmp_cnt++;
    }

    if(tmp_cnt < n) return;

    int Hap = len_hap(tmp_answer,n);

    if(Hap < Answer){
        Answer = Hap;
        for(int i=0; i<n; i++){
            up_answer[i] = tmp_answer[i];
        }
    }
}

int main(int argc, char** argv)
{
    //setbuf(stdout, NULL);
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n,m;
        cin >> n >> m;

        int x,y;
        for(int i=0; i<m; i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        if(n < 9){
            for(int i=0; i<n; i++){
                d_check[i] = 0;
            }

            u_answer = 1000;
            back_tracking(n,0);
            cout << u_answer << endl;
            cout << under_answer[0];
            for(int i=1; i<n; i++){
                cout << " " << under_answer[i];
            }
            cout << endl;

            for(int i=0; i<n; i++){
                v[i].clear();
            }
            continue;
        }

        // n이 클때
        Answer = 100000;

        for(int j=0; j<1000; j++){
            for(int i=0; i<n; i++){
                //각 정점에서 부터 이어진 길을 찾아 길이 비교하기   ex) 1 -> 5 -> 4 -> 3 -> 2 -> 0
                rfs(n,i);
            }
        }

        cout << Answer << endl;
        cout << up_answer[0];
        for(int i=1; i<n; i++){
            cout << " " << up_answer[i];
        }
        cout << endl;
        for(int i=0; i<n; i++){
            v[i].clear();
        }
	}

	return 0;
}
