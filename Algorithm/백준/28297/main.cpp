#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define pi 3.14159265358979
using namespace std;

int n;
vector<vector<double>> v;

struct circle{
    double x,y,r;
};

double dp[1002][1002] = {0};

int parent[1002];

int Find(int x){
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int p_x = Find(x);
    int p_y = Find(y);
    if(p_x == p_y) return;
    parent[p_x] = p_y;
}

int main()
{
    cin >> n;
    circle C[n+1];
    for(int i=1; i<=n; i++){
        parent[i] = i;
        cin >> C[i].x >> C[i].y >> C[i].r;
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            double dist = (C[i].x - C[j].x) * (C[i].x - C[j].x);
            dist += (C[i].y - C[j].y) * (C[i].y - C[j].y);
            double R = (C[i].r + C[j].r) * (C[i].r + C[j].r);
            if(dist <= R){
                dp[i][j] = 0;
                dp[j][i] = 0;
            }
            else{
                double line = dist - (C[i].r - C[j].r)*(C[i].r - C[j].r);
                line = pow(line, 0.5);
                line = 2*line;
                dp[i][j] += line;
                double big_r, small_r;
                if(C[i].r > C[j].r){
                    big_r = C[i].r;
                    small_r = C[j].r;

                }
                else{
                    big_r = C[j].r;
                    small_r = C[i].r;
                }
                dist = pow(dist,0.5);
                double theta = acos((big_r - small_r)/dist);

                dp[i][j] += small_r * 2 * theta;
                dp[i][j] += big_r * (2*pi - 2*theta);
                dp[j][i] = dp[i][j];
            }
            v.push_back(vector<double>{dp[i][j],i,j});
        }
    }
    sort(v.begin(),v.end());
    double sum = 0;
    for(int i=0; i<v.size(); i++){
        double cost = v[i][0];
        int node1 = v[i][1];
        int node2 = v[i][2];
        if(Find(node1) != Find(node2)){
            sum += cost;
            Union(node1, node2);
        }
    }
    cout.precision(15);
    cout << sum;
}
