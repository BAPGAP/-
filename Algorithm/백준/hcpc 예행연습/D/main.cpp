#include <iostream>
#include <cstring>

using namespace std;

int W, H, x1, y1, x2, y2, dx, dy;
bool passed[101][101][2][2];
int conflict;
int nowx, nowy;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int abs(int x) { return (x>0 ? x:-x); }

bool move_ball() {
    nowx += dx;
    nowy += dy;
    if( (nowx==0&&nowy==0) || (nowx==0&&nowy==H) || (nowx==W&&nowy==0) || (nowx==W&&nowy==H) ) {
        ++conflict;
        dx *= -1;
        dy *= -1;
        if( passed[nowx][nowy][dx>0][dy>0] ) return false;
        passed[nowx][nowy][dx>0][dy>0] = true;
        return true;
    }
    if( nowx<=0 ) { ++conflict; dx *= -1; nowx = -nowx; }
    if( nowx>=W ) { ++conflict; dx *= -1; nowx = 2*W-nowx; }
    if( nowy<=0 ) { ++conflict; dy *= -1; nowy = -nowy; }
    if( nowy>=H ) { ++conflict; dy *= -1; nowy = 2*H-nowy; }
    if( passed[nowx][nowy][dx>0][dy>0] ) return false;
    passed[nowx][nowy][dx>0][dy>0] = true;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> W >> H >> x1 >> y1 >> x2 >> y2;
        dx = x2-x1;
        dy = y2-y1;
        int tmp = gcd(max(abs(dx),abs(dy)), min(abs(dx),abs(dy)));
        dx /= tmp;
        dy /= tmp;

        nowx = x2;
        nowy = y2;
        conflict = 0;
        memset(passed, 0, sizeof(passed));

        while(true) {
            bool moved = move_ball();
            if(!moved) {
                //conflict = -1;
                break;
            }
            if(nowx==x2 && nowy==y2) break;
        }

        cout << conflict << '\n';
    }

    return 0;
}
