#include <iostream>
#include <vector>

using namespace std;

int a[6][6] = {0};
pair<int,int> locate[26];


bool check(){
    int cnt = 0;
    for(int i=1; i<=5; i++){
        int sum = 0;
        for(int j=1; j<=5; j++){
            sum += a[i][j];
        }
        if(sum == 5) cnt++;
    }
    for(int j=1; j<=5; j++){
        int sum = 0;
        for(int i=1; i<=5; i++){
            sum += a[i][j];
        }
        if(sum == 5) cnt++;
    }
    int sum = 0;
    for(int i=1; i<=5; i++){
        sum += a[i][i];
    }
    if(sum == 5) cnt++;

    sum = 0;
    for(int i=1; i<=5; i++){
        sum += a[i][6-i];
    }
    if(sum == 5) cnt++;

    if(cnt >= 3) return true;
    else return false;
}

int b[26];

int main()
{
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            int x;
            cin >> x;
            locate[x].first = i;
            locate[x].second = j;
        }
    }

    for(int i=1; i<=25; i++){
        cin >> b[i];
    }

    for(int i=1; i<=25; i++){
        a[locate[b[i]].first][locate[b[i]].second] = 1;
        if(check()){
            cout << i;
            return 0;
        }
    }
}
