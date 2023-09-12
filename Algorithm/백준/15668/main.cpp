#include <iostream>
#include <cmath>

using namespace std;

long long n;
bool visit[10] = {0};
long long sum = 0;
long long Answer = -1;
bool ok = false;

bool check(long long x,long long y){ //x,y의 각자리수가 다 다른가요?
    if(x<=0||y<=0) return false;
    int cnt[10] = {0};
    while(x > 0){
        cnt[x%10]++;
        x /= 10;
    }
    while(y > 0){
        cnt[y%10]++;
        y /= 10;
    }
    for(int i=0; i<10; i++){
        if(cnt[i] > 1) return false;
    }
    return true;
}

void dfs(int x){ //각 자리 모두 다른 x자리 숫자
    if(x==0){
        if(check(n-sum,sum)){
            Answer = max(n-sum,sum);
            ok = true;
        }
        return;
    }
    for(int i=0; i<10; i++){
        if(!visit[i]){
            sum = sum*10 + i;
            visit[i] = true;
            dfs(x-1);
            visit[i] = false;
            sum = (sum - i)/10;
        }
    }
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    //몇자리?
    long long tmp = n;
    int cnt = 0;
    while(tmp > 0){
        cnt++;
        tmp /= 10;
    }
    for(int i=1; i<=cnt; i++){
        if(ok) break;
        dfs(i);
    }

    if(ok) cout << Answer << " + " << n-Answer;
    else cout << "-1";
}
