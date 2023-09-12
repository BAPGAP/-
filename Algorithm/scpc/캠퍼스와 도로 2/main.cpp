#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
vector<pair<int,int>> v[1001];

int able[501][2];
int via[501];
int cnt[501];
bool check[501];
int INF = 2100000000;

void go(int x,int n)
{
    int dis[n+1];
    for(int i=1; i<=n; i++)
    {
        dis[i] = INF;
        able[i][0] = 0;
        able[i][1] = 0;
    }
    dis[x] = 0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,x));

    while(!q.empty())
    {
        int D = -q.top().first; // P까지 총거리
        int P = q.top().second;
        q.pop();
        if(dis[P] < D)
        {
            continue;
        }
        for(int i=0; i<v[P].size(); i++)
        {
            int D_ = v[P][i].second; //P -> P_ 사이 거리
            int P_ = v[P][i].first;
            if(dis[P_] > dis[P] + D_)
            {
                dis[P_] = dis[P] + D_;
                q.push(make_pair(-dis[P_],P_));
            }
        }
    }

    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<v[i].size(); ++j)
        {
            int next=v[i][j].first;
            int cost=v[i][j].second;
            if(dis[i] == dis[next] + cost) // && next != x 다 똑같고 이조건이 들어갔을때 만점이 아니다 왜지!!!!!!!!!!!!
                                           // 드디어 알았다 최소거리 도로의 개수를 셀때 i -> x -> x 가 최소인 경우도 세어야한다.
                                           // 왜냐하면 x -> i , x -> a -> i 모두 최소일때 a를 갈필요가 없다.... 이걸 몰랐다니...
                                           // 이경우를 빼고도 285점이나 주는걸 보면 생각보다 점수가 후한거 같다.
            {
                able[i][0] += 1;
                able[i][1] = next;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(able[i][0] == 1 && able[i][1] != x)
        {
            check[able[i][1]] = true;
        }
    }
}


int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int n,m;
        cin >> n >> m;
        for(int i=1; i<=n; i++)
        {
            check[i] = false;
        }
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            v[a].push_back(make_pair(b,c));
            v[b].push_back(make_pair(a,c));
        }
        for(int i=1; i<=n; i++)
        {
            go(i,n);
        }
        int cnt = 0;

        for(int i=1; i<=n; i++)
        {
            if(check[i]) cnt++;
        }

        cout << "Case #" << test_case+1 << endl;
        cout << cnt;
        for(int i=1; i<=n; i++)
        {
            if(check[i])
            {
                cout << " " << i;
            }
        }
        cout << "\n";

        for(int i=1; i<=n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}
