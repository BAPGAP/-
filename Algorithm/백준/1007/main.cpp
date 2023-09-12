#include <iostream>
#include <cmath>

using namespace std;

struct point{
    long double x,y;
};

point P[21];

long double sum_x;
long double sum_y;
int n;
long double tmp_x;
long double tmp_y;

int Answer[21] = {0};
long double ans;

void dfs(int cnt){
    if(cnt == n/2 + 1){
        long double Z = sqrt((sum_x - 2*tmp_x)*(sum_x - 2*tmp_x) + (sum_y - 2*tmp_y)*(sum_y - 2*tmp_y));
        if(ans > Z) ans = Z;
        return;
    }

    for(int i=1; i<=n; i++){
        if(Answer[cnt-1] < i){
            Answer[cnt] = i;
            tmp_x += P[i].x;
            tmp_y += P[i].y;
            dfs(cnt+1);
            tmp_x -= P[i].x;
            tmp_y -= P[i].y;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int tc=0; tc<T; tc++){
        cin >> n;
        sum_x = 0;
        sum_y = 0;
        for(int i=1; i<=n; i++){
            cin >> P[i].x >> P[i].y;
            sum_x += P[i].x;
            sum_y += P[i].y;
        }
        tmp_x = 0;
        tmp_y = 0;
        ans = 9223372036854775807;
        if(n > 2) dfs(1);
        else{
            ans = sqrt((P[1].x - P[2].x)*(P[1].x - P[2].x) + (P[1].y - P[2].y)*(P[1].y - P[2].y));
        }

        cout << fixed;
        cout.precision(8);
        cout << ans << "\n";
    }
}
