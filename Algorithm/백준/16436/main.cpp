#include <iostream>

using namespace std;

int s[2510][2510] = {0};
int d[2510][2510] = {0};

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int w,h,k;
    cin >> w >> h >> k;
    for(int i=0; i<k; i++){
        int x;
        cin >> x;
        if(x == 1){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            s[b][a]++;
            s[d+1][c+1]++;
            s[d+1][a]--;
            s[b][c+1]--;
        }
        else{
            int a,b,c;
            cin >> a >> b >> c;
            a++;
            b++;
            d[b][a-c]++;
            d[b][a+c+2]++;
            d[b-c-1][a+1]--;
            d[b+c+1][a+1]--;

            d[b][a-c+1]++;
            d[b][a+c+1]++;
            d[b-c][a+1]--;
            d[b+c][a+1]--;
        }
    }

    for(int i=0; i<w; i++){
        for(int j=1; j<h; j++){
            s[j][i] += s[j-1][i];
        }
    }
    for(int i=0; i<h; i++){
        for(int j=1; j<w; j++){
            s[i][j] += s[i][j-1];
        }
    }

    for(int i=1; i<=h+2; i++){
        int tmp = 1;
        while(0 <= i-tmp && tmp <= w+3){
            d[i-tmp][tmp] += d[i-tmp+1][tmp-1];
            tmp++;
        }
    }

    for(int i=1; i<=w+3; i++){
        int tmp = 1;
        while(0 <= h+2-tmp && i+tmp <= w+3){
            d[h+2-tmp][i+tmp] += d[h+2-tmp+1][i+tmp-1];
            tmp++;
        }
    }

    for(int i=1; i<=h+2; i++){
        int tmp = 1;
        while(i+tmp <= h+2 && tmp <= w+3){
            d[i+tmp][tmp] += d[tmp+i-1][tmp-1];
            tmp++;
        }
    }

    for(int i=0; i<=w+3; i++){
        //(0,i)
        int tmp = 1;
        while(tmp <= h+2 && i+tmp <= w+3){
            d[tmp][i+tmp] += d[tmp-1][i+tmp-1];
            tmp++;
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if((s[i][j] + d[i+1][j+1])%2) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
}
