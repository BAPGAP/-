#include <iostream>

using namespace std;

int x[110000];
int y[110000];
int tmp_x[110000];
int tmp_y[110000];
int x1[110000];
int y1[110000];


void Merge_x(int L,int M,int R){
    int cnt = 0;
    int l = L;
    int r = M+1;
    while(1){
        if(l > M || r > R) break;

        if(x[l] > x[r]){
            tmp_x[cnt] = x[r];
            tmp_y[cnt] = y[r];
            r++;
        }
        else{
            tmp_x[cnt] = x[l];
            tmp_y[cnt] = y[l];
            l++;
        }
        cnt++;
    }
    if(l > M){
        for(int i=r; i<=R; i++){
            tmp_x[cnt] = x[i];
            tmp_y[cnt] = y[i];
            cnt++;
        }
    }
    else if(r > R){
        for(int i=l; i<=M; i++){
            tmp_x[cnt] = x[i];
            tmp_y[cnt] = y[i];
            cnt++;
        }
    }
    for(int i=0; i<cnt; i++){
        x[i+L] = tmp_x[i];
        y[i+L] = tmp_y[i];
    }
}
void Sort_x(int L,int R){
    if(L != R){
        int M = (L+R)/2;
        Sort_x(L,M);
        Sort_x(M+1,R);
        Merge_x(L,M,R);
    }
}
void Merge_y(int L,int M,int R){
    int cnt = 0;
    int l = L;
    int r = M+1;
    while(1){
        if(l > M || r > R) break;

        if(y1[l] > y1[r]){
            tmp_x[cnt] = x1[r];
            tmp_y[cnt] = y1[r];
            r++;
        }
        else{
            tmp_x[cnt] = x1[l];
            tmp_y[cnt] = y1[l];
            l++;
        }
        cnt++;
    }
    if(l > M){
        for(int i=r; i<=R; i++){
            tmp_x[cnt] = x1[i];
            tmp_y[cnt] = y1[i];
            cnt++;
        }
    }
    else if(r > R){
        for(int i=l; i<=M; i++){
            tmp_x[cnt] = x1[i];
            tmp_y[cnt] = y1[i];
            cnt++;
        }
    }
    for(int i=0; i<cnt; i++){
        x1[i+L] = tmp_x[i];
        y1[i+L] = tmp_y[i];
    }
}
void Sort_y(int L,int R){
    if(L != R){
        int M = (L+R)/2;
        Sort_y(L,M);
        Sort_y(M+1,R);
        Merge_y(L,M,R);
    }
}

int mn(int a,int b){
    if(a>b) return b;
    return a;
}

int D(int X,int Y){
    return (y[Y] - y[X]) * (y[Y] - y[X]) + (x[Y] - x[X]) * (x[Y] - x[X]);
}
int D1(int X,int Y){
    return (y1[Y] - y1[X]) * (y1[Y] - y1[X]) + (x1[Y] - x1[X]) * (x1[Y] - x1[X]);
}

int dis(int L,int R){
    if(R - L == 1){
        return D(L,R);
    }
    else if(R - L == 2){
        return mn(mn(D(L,L+1),D(R-1,R)),D(L,R));
    }
    else if(L != R){
        int M = (L+R)/2;
        int d_l = dis(L,M);
        int d_r = dis(M+1,R);
        int d = mn(d_l,d_r);

        int line = (x[M] + x[M+1])/2;
        int cnt = 1;

        //라인을 기준으로 거리가 d보다 작은 점들만 새로 저장
        for(int i=L; i<=R; i++){
            if((x[i] - line)*(x[i] - line) < d){
                x1[cnt] = x[i];
                y1[cnt] = y[i];
                cnt++;
            }
        }

        //새로 저장한 애들은 y좌표 기준으로 정렬
        if(cnt > 1) Sort_y(1,cnt-1);

        //새로 저장한 애들끼리 비교, d보다 크면 다음 점으로 넘어감
        for(int i=1; i<cnt; i++){
            for(int j=i+1; j<cnt; j++){
                if((y1[i] - y1[j]) * (y1[i] - y1[j]) > d) break;
                d = mn(d,D1(i,j));
            }
        }
        return d;
    }
}


int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    Sort_x(1,n);
    //현재 x값이 작은순으로 정렬되어 있음

    cout << dis(1,n);
}
