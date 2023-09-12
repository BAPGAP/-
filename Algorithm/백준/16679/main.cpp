#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long six[21];
long long dice[21][121] = {0};

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    six[0] = 1;
    for(int i=1; i<=20; i++){
        six[i] = six[i-1]*6;
    }
    for(int i=1; i<=6; i++){
        dice[1][i] = 1;
    }
    for(int i=2; i<=20; i++){
        for(int j=i; j<=6*i; j++){
            if(j==i) dice[i][j] = 1;
            else{
                for(int k=1; k<=6; k++){
                    dice[i][j] += dice[i-1][j-k];
                }
            }
        }
    }
    for(int i=1; i<=20; i++){
        for(int j=i*6-1; j>=1; j--){
            dice[i][j] += dice[i][j+1];
        }
    }

    //dice[x][y] = x개의 주사위 굴려서 y이상 합 나올 경우의수

    int T;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>> vp;
        vp.push_back({0,0});
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            vp.push_back({x,i});
        }
        sort(vp.begin(),vp.end());
        int sum[21] = {0};
        for(int i=1; i<=n; i++){
            sum[i] = sum[i-1] + vp[i].first;
        }
        if(sum[n] >= k){
            cout << six[n] << "\n";
            for(int i=1; i<=n; i++){
                cout << "0 ";
            }
            cout << "\n";
            continue;
        }

        long double p = 0; //확률
        long long p_value = 0; //확률 분자
        int mx = 0; //그때 새로 주사위 개수

        for(int i=1; i<=n; i++){ //주사위를 i번 새로 굴렸을때
            int tmp = k - (sum[n] - sum[i]); //i번 굴려서 tmp이상 이어야됨
            long double q = (long double)dice[i][tmp]/six[i];
            if(q > p){
                p = q;
                p_value = dice[i][tmp] * six[n-i];
                mx = i;
            }
        }

        cout << p_value << "\n";
        vector<pair<int,int>> vp_1;
        for(int i=1; i<=n; i++){
            if(i <= mx) vp_1.push_back({vp[i].second,1});
            else vp_1.push_back({vp[i].second,0});
        }
        sort(vp_1.begin(),vp_1.end());
        for(int i=0; i<vp_1.size(); i++){
            cout << vp_1[i].second << " ";
        }
        cout << "\n";
    }
}
